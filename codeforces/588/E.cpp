#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(x, v) for (auto &x : v)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)

const int N = 1 << 17, K = 10;

int sz[N], ch[N], pos[N], p[N], in[N], timer = 0;
vector<int> g[N] = {{0}}, z[N];

int lo, hi, k;
struct T {
	int n; vector<vector<int>> t;
	vector<int> nodes;

	void init() {
		n = sz(nodes);
		int sz = 1; while (sz < n) sz <<= 1;
		t.resize(2 * sz);
		build(1, 0, n);
	}

	void build(int v, int l, int r) {
		if (r - l == 1) return void(t[v] = z[nodes[l]]);
		int m = l + r >> 1;
		build(v << 1|0, l, m); build(v << 1|1, m, r);
		t[v].resize(sz(t[v << 1|0]) + sz(t[v << 1|1]));
		merge(all(t[v << 1|0]), all(t[v << 1|1]), begin(t[v]));
		if (K < sz(t[v])) t[v].resize(K);
	}

	void query(vector<int> &z, int v, int l, int r) {
		if (r <= lo || hi <= l) return;
		if (lo <= l && r <= hi) {
			if (sz(t[v]) < k) z = {all(t[v])};
			else z = {begin(t[v]), begin(t[v]) + k};
			return;
		}
		vector<int> zl, zr; int m = l + r >> 1;
		query(zl, v << 1|0, l, m); query(zr, v << 1|1, m, r);
		z.resize(sz(zl) + sz(zr));
		merge(all(zl), all(zr), begin(z));
		if (k < sz(z)) z.resize(k);
	}

	vector<int> query(int l, int r) {
		if (l > r) swap(l, r); lo = l; hi = r + 1;
		vector<int> z;
		query(z, 1, 0, n);
		return z;
	}
};
vector<T> t;

void dfs(int u, int a) {
	in[u] = ++timer; sz[u] = 1; p[u] = a;
	g[u].erase(find(all(g[u]), a));
	if (g[u].empty()) ch[u] = sz(t), t.eb();
	else {
		int mx = g[u].front();
		trav(v, g[u]) {
			if (v == a) continue;
			dfs(v, u); sz[u] += sz[v];
			if (sz[mx] < sz[v]) mx = v;
		}
		ch[u] = ch[mx], pos[u] = pos[mx] + 1;
	}
	t[ch[u]].nodes.eb(u);
}
int head(int u) { return t[ch[u]].nodes.back(); }
int ancestor(int u, int v) { return in[u] <= in[v] && in[v] < in[u] + sz[u]; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >> n >> m >> q;
	rep(i, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].eb(v); g[v].eb(u);
	}
	dfs(0, 0);
	rep(i, 0, m) { int x; cin >> x; if (sz(z[--x]) < K) z[x].eb(i + 1); }
	rep(i, 0, sz(t)) t[i].init();
	while (q--) {
		int u, v; cin >> u >> v >> k; --u; --v;
		vector<int> x, z;
		while (ch[u] != ch[v]) {
			if (!ancestor(head(u), v)) {
				z = t[ch[u]].query(pos[head(u)], pos[u]);
				u = p[head(u)];
			} else {
				z = t[ch[v]].query(pos[head(v)], pos[v]);
				v = p[head(v)];
			}
			x.insert(end(x), all(z));
		}
		z = t[ch[u]].query(pos[u], pos[v]);
		x.insert(end(x), all(z));

		sort(all(x)); if (k < sz(x)) x.resize(k);
		cout << sz(x) << ' '; trav(z, x) cout << z << ' '; cout << '\n';
	}
}