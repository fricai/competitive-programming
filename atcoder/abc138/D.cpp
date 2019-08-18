#include <iostream>
#include <vector>
using namespace std;
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)

vector<vector<int>> adj;
vector<long long> diff;
vector<int> invt, length;
int t = 0;

void dfs(int u, int p) {
	invt[u] = t++;
	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			length[u] += length[v];
		}
}

signed main() {
	int n, q; cin >> n >> q;
	adj.resize(n);
	invt.resize(n);
	diff.resize(n + 1);
	length.resize(n, 1);
	REP(i, 1, n) {
		int a, b; cin >> a >> b; --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1);
	while(q--) {
		int p, x; cin >> p >> x; --p;
		diff[invt[p]] += x;
		diff[invt[p] + length[p]] -= x;
	}
	REP(i, 1, n) diff[i] += diff[i - 1];
	REP(i, 0, n) cout << diff[invt[i]] << ' ';
}