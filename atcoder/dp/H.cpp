#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)

using ll = int64_t;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

constexpr ll inf = 2e18;
constexpr int M = 1e9 + 7;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w; cin >> h >> w;
	char g[h][w];
	int dp[h + 1][w + 1];
	rep(i, 0, h) rep(j, 0, w) cin >> g[i][j];
	rep(i, 0, h) dp[i + 1][0] = 0;
	rep(j, 0, w) dp[0][j + 1] = 0;
	dp[0][1] = 1;
	rep(i, 0, h)
		rep(j, 0, w)
			dp[i + 1][j + 1] = g[i][j] != '#' ? (dp[i + 1][j] + dp[i][j + 1]) % M : 0;
	cout << dp[h][w];
}