#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

int n, m, d, inf = 1e9;
vector<vector<int>> adj;
vector<int> out, in;
vector<bool> mark;

void in_dfs(int, int);
void out_dfs(int, int);

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> d;

	mark.resize(n + 1, 0);
	while(m--) {
		int x; cin >> x; mark[x] = 1;
	}

	adj.resize(n + 1); adj[1].push_back(0);
	REP(i, 1, n) {
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	in.resize(n + 1, -inf); in_dfs(1, 0);
	out.resize(n + 1, -inf); out_dfs(1, 0);

	int ans = 0;
	REP(i, 1, n + 1) ans += (max(in[i], out[i]) <= d);
	cout << ans;
}

void in_dfs(int u, int p) {
	if (mark[u]) in[u] = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		in_dfs(v, u);
		in[u] = max(in[u], in[v] + 1);
	}

	if (in[u] < 0) in[u] = -inf;
}

void out_dfs(int p, int g) {
	int mx1 = -inf, mx2 = -inf;

	for (int u : adj[p]) { // u are the children of p
		if (u == g) continue;
		if (in[u] >= mx1) mx2 = mx1, mx1 = in[u];
		else if (in[u] > mx2) mx2 = in[u];
	}

	for (int u : adj[p]) {
		if (u == g) continue;

		if (mark[p]) out[u] = 1;
		out[u] = max(out[u], out[p] + 1);
		out[u] = max(out[u], ((mx1 != in[u]) ? mx1 : mx2) + 2);
		if (out[u] < 0) out[u] = -inf;

		out_dfs(u, p);
	}
}
