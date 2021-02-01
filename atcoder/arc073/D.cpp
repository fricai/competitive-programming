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

// let dp[i][j][k] = max value from first i items using weight j * w(1) + k, 0 <= k <= 3 * j 
// 

const int N = 1 << 7;
map<ll, ll> dp[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, W; cin >> n >> W;

	dp[0][0] = 0;
	rep(i, 0, n) {
		int w, v; cin >> w >> v;
		dp[i + 1] = dp[i];
		for (auto [x, y] : dp[i]) if (x + w <= W) ckmax(dp[i + 1][x + w], y + v);
	}

	ll ans = 0;
	for (auto [x, y] : dp[n]) ckmax(ans, y);
	cout << ans;
}