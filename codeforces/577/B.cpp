#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

bool solve() {
	int n, m; cin >> n >> m;
	if (n > m) return true;
	int a[n], dp[n][m];
	REP(i, 0, n)
		cin >> a[i],
		a[i] %= m;
	REP(i, 0, n) REP(j, 0, m) dp[i][j] = false;
	dp[0][a[0]] = true;
	REP(i, 1, n) {
		dp[i][a[i]] = true;
		REP(j, 0, m)
			dp[i][j] |= dp[i - 1][(j + m - a[i]) % m] || dp[i - 1][j];
	}
	return dp[n - 1][0];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << (solve() ? "YES" : "NO");
}