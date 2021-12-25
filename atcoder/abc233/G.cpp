#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<string> g(n);
	for (auto &row : g)
		cin >> row;

	vector dp(n, vector(n, vector(n, vector(n, -1))));
	auto dps = [&](const auto &f, int l, int r, int d, int u) -> int {
		if (l > r || d > u)
			return 0;

		if (~dp[l][r][d][u])
			return dp[l][r][d][u];
		dp[l][r][d][u] = max(r - l + 1, u - d + 1);
		// vertical empty line
		
		for (int i = l; i <= r; ++i) {
			if ([&]() -> bool {
					for (int j = d; j <= u; ++j)
						if (g[i][j] == '#')
							return false;
					return true;
				}()) {
				uin(dp[l][r][d][u], f(f, l, i - 1, d, u) + f(f, i + 1, r, d, u));
			}
		}

		for (int j = d; j <= u; ++j) {
			if ([&]() -> bool {
					for (int i = l; i <= r; ++i)
						if (g[i][j] == '#')
							return false;
					return true;
				}()) {
				uin(dp[l][r][d][u], f(f, l, r, d, j - 1) + f(f, l, r, j + 1, u));
			}
		}
		return dp[l][r][d][u];
	};
	cout << dps(dps, 0, n - 1, 0, n - 1) << '\n';
}
