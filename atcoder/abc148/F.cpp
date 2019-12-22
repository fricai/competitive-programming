#include <vector>
#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;

const int N = 1e5;
vector<int> g[N];
int p[N], h[N], d[N];

void dfs(int u) {
	if (p[u] != -1) d[u] = d[p[u]] + 1;
	else d[u] = 0;

	h[u] = 0;
	for (int v : g[u]) {
		if (v != p[u]) {
			p[v] = u;
			dfs(v);
			h[u] = max(h[u], h[v] + 1);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, A, T; cin >> n >> T >> A; --T, --A;
	REP(i, 1 , n) {
		int u, v; cin >> u >> v; --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	p[A] = -1; dfs(A);
	int ans = 0;
	int steps = 0;
	int cur = T;
	while (steps < d[cur]) {
		ans = max(ans, d[cur] + h[cur] - 1);
		cur = p[cur];
		++steps;
	}
	cout << ans;
}