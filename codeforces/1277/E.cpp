#include <iostream>
#include <vector>
#include <queue>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const int N = 1 << 18;
vector<int> g[N];
bool vis[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n, m, a[2];
		
		cin >> n >> m >> a[0] >> a[1]; --a[0], --a[1];
		while (m--) {
			int u, v; cin >> u >> v; --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		int cnt[2];
		auto bfs = [&](bool b) {
			vis[a[!b]] = true; cnt[b] = 0;
			queue<int> q; q.push(a[b]);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (vis[u]) continue;
				vis[u] = true;
				for (int v : g[u]) q.push(v);
			}
			REP(i, 0, n) {
				if (!vis[i]) ++cnt[b];
				else vis[i] = false;
			}
		};
		bfs(0); bfs(1);
		
		cout << 1LL * cnt[0] * cnt[1] << '\n';
		REP(i, 0, n) g[i].clear();
	}
}