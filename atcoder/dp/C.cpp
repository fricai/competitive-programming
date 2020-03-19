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

	ll dp[n + 1][3] = {{0, 0, 0}};
	rep(i, 0, n) {
		dp[i + 1][0] = max(dp[i][1], dp[i][2]) + c[i][0];
		dp[i + 1][1] = max(dp[i][2], dp[i][0]) + c[i][1];
		dp[i + 1][2] = max(dp[i][0], dp[i][1]) + c[i][2];
	}
	cout << max({dp[n][0], dp[n][1], dp[n][2]});
}