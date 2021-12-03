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
	vector<vector<int>> g(n);
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int a = 0;
	rep(u, 0, n) a += sz(g[u]) & 1;
	a /= 2;

	int root = 0;
	while (sz(g[root]) > 1) ++root;

	auto reroot = [&](const auto &self, int u) -> void {
		for (auto v : g[u]) {
			g[v].erase(find(all(g[v]), u));
			self(self, v);
		}
	};
	reroot(reroot, root);
	for (auto &v : g)
		if (~sz(v) & 1)
			v.push_back(n);

	int l = 0, r = n - 1;
	while (r - l > 1) {
		int b = (l + r) / 2;

		vector<int> dp(n + 1);
		auto dfs = [&](const auto &self, int u) -> void {
			if (u == n)
				return;

			for (auto v : g[u]) {
				self(self, v);
			}

			sort(all(g[u]), [&](int x, int y) {
					return dp[x] < dp[y];
					});

			int m = sz(g[u]);
			for (int i = 0, j = m - 2; i < j; ++i, --j) {
				if (dp[g[u][i]] + dp[g[u][j]] > b) {
					dp[u] = b + 2;
					return;
				}
			}

			int x = m - 1;
			while (x > 0) {
				if (x > (m - 1) / 2) {
					if (dp[g[u][x]] + dp[g[u][m - 1 - x]] > b)
						break;
				} else {
					if (dp[g[u][x]] + dp[g[u][m - x]] > b)
						break;
				}
				--x;
			}
			dp[u] = dp[g[u][x]] + 1;
		};

		dfs(dfs, root);

		(dp[root] <= b + 1 ? r : l) = b;
	}

	cout << a << ' ' << r << '\n';
}
