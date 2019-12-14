#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const int N = 1 << 18;

int a[2];
vector<int> g[N], r[2], s[2];
bool vis[N];

void dfs(int u, bool b) {
	if (vis[u]) return;
	vis[u] = true;
	if (u != a[!b])
		for (int v : g[u])
			dfs(v, b);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m >> a[0] >> a[1]; --a[0], --a[1];
		while (m--) {
			int u, v; cin >> u >> v; --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		auto stuff = [&](bool b) {
			dfs(a[b], b);
			REP(i, 0, n) {
				if (vis[i]) {
					r[b].push_back(i);
					vis[i] = false;
				}
			}
		};
		stuff(0); stuff(1);
		REP(j, 0, 2)
			set_difference(r[j].begin(), r[j].end(), r[!j].begin(), r[!j].end(), inserter(s[j], s[j].begin()));
		
		cout << 1LL * s[0].size() * s[1].size() << '\n';
		REP(i, 0, n) g[i].clear();
		REP(j, 0, 2) r[j].clear();
		REP(j, 0, 2) s[j].clear();
	}
}