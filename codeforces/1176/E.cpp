#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

vector<vector<int>> adj;
vector<bool> ans, vis;
int k = 0;

void dfs(int v, bool b) {
	if (vis[v]) return;
	vis[v] = 1;
	if (b) {
		ans[v] = 1;
		++k;
	}
	for (auto &u : adj[v]) dfs(u, !b);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--) {
		int n, m; cin >> n >> m;
		adj.resize(n); vis.resize(n, 0); ans.resize(n, 0);
		while(m--) {
			int u, v; cin >> u >> v; --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(0, 0);

		if (k <= n/2) {
			cout << k << '\n';
			REP(i, 0, n)
				if (ans[i])
					cout << i + 1 << ' ';
			cout << '\n';
		}	else {
			cout << n - k << '\n';
			REP(i, 0, n)
				if (!ans[i]) cout << i + 1 << ' ';
			cout << '\n';
		}

		adj.clear(); vis.clear(); ans.clear(); k = 0;
	}
}
