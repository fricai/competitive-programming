#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 13, B = 60, inf = 2e9;
int deg[N];
ll a[N], b[N];
bool dead[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];

	ll s = 0;
	rep(i, 0, n) s += b[i];
	rep(i, 0, n)
		rep(j, 0, n)
			if (a[i] & ~a[j]) ++deg[i];

	
	int cur = n - 1;

	int idx = -1;
	ll mn = inf;
	rep(i, 0, n) if (deg[i] == n - 1 && ckmin(mn, b[i])) idx = i;

	while (0 <= idx) {
		dead[idx] = 1; s -= b[idx]; --cur;

		mn = inf;
		int nxt = -1;
		rep(j, 0, n)  {
			if (dead[j]) continue;
			if (a[j] & ~a[idx]) --deg[j];
			if (deg[j] == cur && ckmin(mn, b[j]))
				nxt = j;
		}
		idx = nxt;
	}
	cout << s;
}