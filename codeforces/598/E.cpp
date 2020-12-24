#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 30, K = 50;
int dp[N + 1][N + 1][K + 1];
// int f(int n, int m, int k) {
// 	if (k < 0 || k > n * m) return 1e9;
// 	if (k == 0 || k == n * m) return 0;
// 	if (dp[n][m][k] != -1) return dp[n][m][k];
	
// 	int a = 1e9;
// 	for (int i = 1; i <= m - i; ++i)
// 		for (int r = 0; r <= k; ++r)
// 			ckmin(a, f(n, i, r) + f(n, m - i, k - r));
// 	a += n * n;

// 	int b = 1e9;
// 	for (int i = 1; i <= n - i; ++i)
// 		for (int r = 0; r <= k; ++r)
// 			ckmin(b, f(i, m, r) + f(n - i, m, k - r));
// 	b += m * m;
// 	return dp[n][m][k] = min(a, b);
// }

int solve() {
	int n, m, k; cin >> n >> m >> k;
	return dp[n][m][k];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int n = 1; n <= N; ++n) {
		for (int m = 1; m <= N; ++m) {
			for (int k = 1; k <= K; ++k) {

				if (k == n * m) continue;

				dp[n][m][k] = 1e9;
				if (k > n * m) continue;
				
				for (int r = 0; r <= k; ++r) {
					for (int i = 1; i <= n - i; ++i)
						ckmin(dp[n][m][k], dp[i][m][r] + dp[n - i][m][k - r] + m * m);
					for (int j = 1; j <= m - j; ++j)
						ckmin(dp[n][m][k], dp[n][j][r] + dp[n][m - j][k - r] + n * n);
				}
			}
		}
	}

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}