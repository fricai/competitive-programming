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

const int N = 1 << 7;
const ll inf = 1e18 + 5e9;
ll dp[2][N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; ll x; cin >> n >> x;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	ll ans = inf;
	for (int k = 1; k <= n; ++k) {
		rep(j, 0, k)
			for (int r = 0; r <= k; ++r)
				dp[0][j][r] = dp[1][j][r] = -inf;
		
		dp[0][0][0] = 0;
		for (int i = 0, cur = 1, pre = 0; i < n; ++i, cur ^= 1, pre ^= 1) {
			int w = a[i];
			rep(j, 0, k)
				for (int r = 0; r <= k; ++r)
					dp[cur][j][r] = dp[pre][j][r];
			rep(j, 0, k)
				for (int r = 0; r < k; ++r) {
					ll nxt = dp[pre][j][r] + w;
					if (nxt <= x) ckmax(dp[cur][(j + w) % k][r + 1], nxt);
				}
		}
		
		ll ok = dp[n & 1][x % k][k];
		if (ok > 0) {
			assert((x - ok) % k == 0);
			ckmin(ans, (x - ok) / k);
		}
	}
	cout << ans;
}