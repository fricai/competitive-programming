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

const int N = 1 << 19;
int n[3];
int a[3][N];
ll sum[3];
ll mn[3];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(i, 0, 3) cin >> n[i];

	ll s = 0;
	rep(i, 0, 3) {
		rep(j, 0, n[i]) cin >> a[i][j], sum[i] += a[i][j];
		mn[i] = *min_element(a[i], a[i] + n[i]);
		s += sum[i];
	}

	ll ans = 0;
	rep(i, 0, 3) {
		ckmax(ans, s - 2 * sum[i]);
		rep(j, 0, i)
			ckmax(ans, s - 2 * (mn[i] + mn[j]));
	}
	cout << ans;
}