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

	int n; cin >> n;
	ll c[n][3];
	rep(i, 0, n) rep(a, 0, 3) cin >> c[i][a];

	ll dp[n][3];
	dp[0][0] = c[0][0];	dp[0][1] = c[0][1];	dp[0][2] = c[0][2];
	rep(i, 1, n) {
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + c[i][0];
		dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + c[i][1];
		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i][2];
	}
	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}