#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 18;
vector<int> g[N];
int n, sz[N], pre[N], nxt[N], p[N], d[N];

int get_dist(int u) {
	assert(0 <= u && u < n);
	cout << "d " << u + 1 << '\n';
	int res; cin >> res;
	assert(res != -1);
	return res;
}

int get_child(int u) {
	assert(0 <= u && u < n);
	cout << "s " << u + 1 << '\n';
	int res; cin >> res;
	assert(res != -1);
	return res - 1;
}

int answer(int u) {
	assert(0 <= u && u < n);
	cout << "! " << u + 1;
	return 0;
}

void dfs(int u, int p) {
	g[u].erase(remove(begin(g[u]), end(g[u]), p), end(g[u]));
	sz[u] = 1; ::p[u] = p;
	trav(v, g[u]) {
		if (v == p) continue;
		d[v] = d[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
		if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
	}
}

void dfs(int u) {
	nxt[u] = u;
	trav(v, g[u]) {
		pre[v] = v == g[u][0] ? pre[u] : v;
		dfs(v);
		if (v == g[u][0])
			nxt[u] = nxt[v];
	}
}

signed main() {
	ios::sync_with_stdio(false);

	cin >> n;
	rep(i, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(0, -1);
	dfs(0);

	int dx = get_dist(0);
	if (dx == 0) return answer(0);
	int root = 0;
	while (true) {
		int u = nxt[root], v = u;
		int dist = get_dist(u);
		while (dist != d[u] + dx - 2 * d[v]) v = p[v];
		if (d[v] == dx) return answer(v);
		root = get_child(v);
	}
}