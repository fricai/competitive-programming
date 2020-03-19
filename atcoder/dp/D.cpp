#include <algorithm>
#include <iostream>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

using ll = int64_t;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll inf = 2e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, w; cin >> n >> w;
	ll v[n], c[n]; rep(i, 0, n) cin >> c[i] >> v[i];

	ll dp[n][w + 1];
	rep(i, 0, n) dp[i][0] = 0;
	rep(x, 0, w + 1) dp[0][x] = c[0] <= x ? v[0] : 0;
	rep(i, 1, n)
		rep(x, 1, w + 1) {
			dp[i][x] = dp[i - 1][x];
			if (c[i] <= x)
				ckmax(dp[i][x], dp[i - 1][x - c[i]] + v[i]);
		}
	cout << dp[n - 1][w];
}