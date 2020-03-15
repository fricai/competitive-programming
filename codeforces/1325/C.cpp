#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define eb(x...) emplace_back(x)

using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<vector<int>> g(n);
	vector<pii> edges(n - 1);
	map<pii, int> e;
	int x = -1;
	rep(i, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].eb(v);
		g[v].eb(u);
		if (sz(g[u]) > 2) x = u;
		if (sz(g[v]) > 2) x = v;
		if (u > v) swap(u, v);
		edges[i - 1] = {u, v};
	}
	if (x == -1) rep(i, 0, n - 1) cout << i << '\n';
	else {
		int cntr = 0;
		trav(v, g[x]) {
			if (x > v) e[{v, x}] = cntr++;
			else e[{x, v}] = cntr++;
		}
		trav(s, edges) {
			auto it = e.find(s);
			if (it == end(e)) cout << cntr++ << '\n';
			else cout << it->second << '\n';
		}
	}
}