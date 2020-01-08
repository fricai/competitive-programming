#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const int N = 1 << 19;
vector<int> g[N];
int sz[N], in[N], p[N], nxt[N], n, timer = 0;

bool t[N << 1], u[N << 1];

void dfs_sz(int u = 0, int a = -1) {
	sz[u] = 1; p[u] = a;
	g[u].erase(remove(g[u].begin(), g[u].end(), a), g[u].end());
	for (int &v : g[u]) {
		dfs_sz(v, u);
		sz[u] += sz[v];
		if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
	}
}

void dfs_hld(int u = 0) {
	in[u] = timer++;
	for (int v : g[u]) {
		nxt[v] = (v != g[u][0] ? v : nxt[u]);
		dfs_hld(v);
	}
}

void push(int v) {
	if (u[v]) {
		t[v << 1] = t[v << 1|1] = t[v];
		u[v << 1] = u[v << 1|1] = true;
		u[v] = false;
	}
}

void modify(int lo, int hi, bool val, int v = 1, int l = 0, int r = n - 1) {
	if (l == lo && r == hi) {
		t[v] = val;
		u[v] = true;
	} else {
		push(v);
		int m = (l + r) / 2;
		if (hi <= m) modify(lo, hi, val, v << 1, l, m);
		else if (lo > m) modify(lo, hi, val, v << 1|1, m + 1, r);
		else {
			modify(m + 1, hi, val, v << 1|1, m + 1, r);
			modify(lo, m, val, v << 1, l, m);
		}
	}
}

bool query(int p, int v = 1, int l = 0, int r = n - 1) {
	if (l == r) return t[v];
	push(v);
	int m = (l + r) / 2;
	if (p <= m) return query(p, v << 1, l, m);
	else return query(p, v << 1|1, m + 1, r);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	rep(i, 1, n) {
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs_sz(); dfs_hld();

	int q; cin >> q;
	while (q--) {
		int c, v; cin >> c >> v; --v;
		if (c == 1) modify(in[v], in[v] + sz[v] - 1, 1);
		if (c == 2)
		    while (v != -1) {
		        modify(in[nxt[v]], in[v], 0);
		        v = p[nxt[v]];
		    }
		if (c == 3) cout << query(in[v]) << '\n';
	}
}