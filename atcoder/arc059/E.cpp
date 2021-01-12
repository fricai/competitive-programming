#include <bits/stdc++.h>
#include <atcoder/modint>

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

const int N = 1 << 9, M = 1e9 + 7;
using mint = atcoder::static_modint<M>;
mint pw[N][N], sum[N][N];
bool vis[N][N];
mint dp[N][N];
int a[N], b[N];

// sum[i][j] = sum r^j from r = [0, i]

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(i, 0, N) {
		pw[i][0] = 1;
		mint z = i;
		rep(j, 1, N) pw[i][j] = z * pw[i][j - 1];
	}

	rep(i, 1, N) rep(j, 0, N) sum[i][j] = sum[i - 1][j] + pw[i][j];

	int n, c; cin >> n >> c;
	// let f(n, c) = sum x
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];

	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= c; ++j)
			for (int r = 0, p = j; r <= j; ++r, --p)
				dp[i][j] += (sum[b[i]][r] - sum[a[i] - 1][r]) * dp[i - 1][p];
	cout << dp[n][c].val();
}