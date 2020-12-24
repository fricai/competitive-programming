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

const int N = 40, K = 70;
int dp[N][N][K];
int f(int n, int m, int k) {
	if (k < 0 || k > n * m) return 1e9;
	if (k == 0 || k == n * m) return 0;
	if (dp[n][m][k] != -1) return dp[n][m][k];
	
	int a = 1e9;
	for (int i = 1; i < m; ++i)
		for (int r = 0; r <= k; ++r)
			ckmin(a, f(n, i, r) + f(n, m - i, k - r));
	a += n * n;

	int b = 1e9;
	for (int i = 1; i < n; ++i)
		for (int r = 0; r <= k; ++r)
			ckmin(b, f(i, m, r) + f(n - i, m, k - r));
	b += m * m;
	return dp[n][m][k] = min(a, b);
}

int solve() {
	int n, m, k; cin >> n >> m >> k;
	return f(n, m, k);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(i, 0, N) rep(j, 0, N) rep(k, 0, K) dp[i][j][k] = -1;
	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}