#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

vector<vector<int>> adj;
vector<int> leafdist;

void dfs(int u, int s) {
	for (int v : adj[u]) {
		if (v == s) continue;
		dfs(v, u);
		leafdist[u] = max(leafdist[u], leafdist[v] + 1);
	}
}

signed main() {
	int n; cin >> n;
	map<string, int> name;
	name["Polycarp"] = 0;

	adj.resize(n + 1); leafdist.resize(n + 1, 1); adj[0].emplace_back(-1);
	REP(i, 0, n) {
		string S[3]; cin >> S[0] >> S[1] >> S[2];
		transform(S[0].begin(), S[0].end(), S[0].begin(), ::tolower);
		transform(S[2].begin(), S[2].end(), S[2].begin(), ::tolower);

		int &v = name[S[0]], &u = name[S[2]];
		v = i + 1;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(0, -1);
	int ans = 0;
	REP(i, 0, n + 1) ans = max(ans, leafdist[i]);
	cout << ans;
}
