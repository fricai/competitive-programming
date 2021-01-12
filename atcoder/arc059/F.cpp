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

const int N = 5e3 + 5, M = 1e9 + 7;
using mint = atcoder::static_modint<M>;
mint dp[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	string s; cin >> s;
	dp[0][0] = 1;
	for (int m = 1; m <= n; ++m) {
		dp[0][m] = dp[0][m - 1] + dp[1][m - 1] + dp[1][m - 1];
		for (int i = 1; i <= m; ++i)
			dp[i][m] = dp[i + 1][m - 1] + dp[i + 1][m - 1] + dp[i - 1][m - 1];
	}
	cout << dp[sz(s)][n].val();
}