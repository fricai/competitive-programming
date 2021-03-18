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

const int N = 150 + 10, inf = 1e9;
int q[N], dp[2][N][N * N / 2];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, s; cin >> n >> k >> s;
	rep(i, 0, n) cin >> q[i];

	s = min(n * (n - 1) / 2, k * (k - 1) / 2 + s);

	for (int j = 0; j <= k; ++j)
		for (int x = 0; x <= s; ++x)
			dp[0][j][x] = inf;
	dp[0][0][0] = 0;

	for (int i = 0, cur = 1; i < n; ++i, cur ^= 1) {
		for (int j = 0; j <= k; ++j)
			for (int x = 0; x <= s; ++x)
				dp[cur][j][x] = dp[!cur][j][x];
	
		for (int j = 0; j < k; ++j)
			for (int x = i; x <= s; ++x)
				ckmin(dp[cur][j + 1][x], q[i] + dp[!cur][j][x - i]);
	}
	int ans = inf;
	rep(i, k * (k - 1) / 2, s + 1) ckmin(ans, dp[n & 1][k][i]);
	cout << ans;
}