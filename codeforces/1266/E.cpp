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

const int N = 1 << 18;
int a[N], c[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll cur = 0;

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i + 1], cur += a[i + 1];

	map<pair<int, int>, int> m;
	int q; cin >> q;
	while (q--) {
		int s, t, u; cin >> s >> t >> u;
		int &v = m[{s, t}];
		if (v) {
			cur -= max(a[v] - c[v], 0);
			--c[v];
			cur += max(a[v] - c[v], 0);
		}
		if (u) {
			cur -= max(a[u] - c[u], 0);
			++c[u];
			cur += max(a[u] - c[u], 0);
		}
		v = u;
		
		cout << cur << '\n';
	}
}