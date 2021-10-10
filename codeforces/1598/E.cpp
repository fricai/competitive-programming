#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >> n >> m >> q;

	vector dp(n, vector(m, vector(2, 0)));
	vector g(n, vector(m, 1));

	auto solve = [&](int i, int j) {
		if (g[i][j]) {
			dp[i][j][0] = i > 0 ? 1 + dp[i - 1][j][1] : 1;
			dp[i][j][1] = j > 0 ? 1 + dp[i][j - 1][0] : 1;
		} else {
			dp[i][j][0] = 0;
			dp[i][j][1] = 0;
		}
	};

	auto f = [&](int i, int j) {
		return max(0, dp[i][j][0] + dp[i][j][1] - 1);
	};

	ll ans = 0;
	rep(i, 0, n)
		rep(j, 0, m) {
			solve(i, j);
			ans += f(i, j);
		}

	while (q--) {
		int x, y; cin >> x >> y; --x; --y;
		g[x][y] ^= 1;
		for (auto b : {0, 1}) {
			for (int i = x, j = y; i < n && j < m; b ^= 1) {
				ans -= f(i, j);
				solve(i, j);
				ans += f(i, j);

				if (b) ++i;
				else ++j;
			}
		}

		cout << ans << '\n';
	}
}
