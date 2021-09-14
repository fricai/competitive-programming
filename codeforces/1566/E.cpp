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

int solve() {
	int n; cin >> n;
	vector<vector<int>> g(n);
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int buds = 0;
	vector<int> deg(n);
	vector<bool> bud(n), leaf(n);
	auto dfs = [&](const auto &self, int u) -> void {
		int bud_children = 0, leaf_children = 0;
		for (auto v : g[u]) {
			g[v].erase(find(all(g[v]), u));
			self(self, v);

			if (bud[v]) {
				++bud_children;
				assert(deg[v] != 0);
			} else {
				if (deg[v] == 0)
					++leaf_children;
				++deg[u];
			}
			
		}
		if (u != 0) {
			if (deg[u] != 0 && leaf_children == deg[u]) {
				bud[u] = true;
				++buds;
			}
		}
	};
	dfs(dfs, 0);

	for (auto v : g[0])
		if (deg[v] == 0)
			return (n - 1 - buds) - buds;
	return (n - 1 - buds) - buds + 1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
