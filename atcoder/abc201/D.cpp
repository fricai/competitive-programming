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

const int N = 1 << 11, inf = 1e9;
int dp[N][N], a[N][N];

void verdict(int x) {
	if (x == 0) cout << "Draw\n";
	else cout << (x > 0 ? "Takahashi" : "Aoki") << '\n';
	exit(0);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	rep(i, 0, n) rep(j, 0, m) {
		char c; cin >> c;
		a[i][j] = c == '+' ? +1 : -1;
	}

	per(i, 0, n) {
		per(j, 0, m) {
			if (i == n - 1 && j == m - 1)
				dp[n - 1][m - 1] = 0;
			else if ((i + j) % 2 == 0) {
				// 0 maximizes
				dp[i][j] = -inf;
				if (i + 1 < n) ckmax(dp[i][j], dp[i + 1][j] + a[i + 1][j]);
				if (j + 1 < m) ckmax(dp[i][j], dp[i][j + 1] + a[i][j + 1]);
			} else {
				dp[i][j] = +inf;
				if (i + 1 < n) ckmin(dp[i][j], dp[i + 1][j] - a[i + 1][j]);
				if (j + 1 < m) ckmin(dp[i][j], dp[i][j + 1] - a[i][j + 1]);
			}
		}
	}
	verdict(dp[0][0]);
}