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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 17;

int sz[N], ch[N], pos[N], p[N], in[N], c = 1, timer = 0;
vector<int> g[N] = {{0}}, z[N];

int lo, hi, k;
struct T {
	int n; vector<vector<int>> t;
	vector<int> nodes;
	T() { }
	void insert(int v) { nodes.eb(v); }
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
} t[N];

void dfs_init(int u = 0, int a = 0) {
	sz[u] = 1; p[u] = a;
	g[u].erase(find(all(g[u]), a));
	trav(v, g[u]) {
		dfs_init(v, u);
		sz[u] += sz[v];
		if (sz[g[u][0]] < sz[v]) swap(v, g[u][0]);
	}
}
void dfs_hld(int u = 0) {
	in[u] = ++timer;
	trav(v, g[u]) {
		if (v != g[u][0]) ch[v] = c++;
		else {
			ch[v] = ch[u];
			pos[v] = pos[u] + 1;
		}
		t[ch[v]].insert(v);
		dfs_hld(v);
	}
}
int head(int u) { return t[ch[u]].nodes[0]; }
int ancestor(int u, int v) {
	return in[u] <= in[v] && in[v] < in[u] + sz[u];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >> n >> m >> q;
	rep(i, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].eb(v); g[v].eb(u);
	}
	t[0].insert(0); dfs_init(); dfs_hld();
	rep(i, 0, m) { int x; cin >> x; z[--x].eb(i + 1); }
	rep(i, 0, c) t[i].init();

	while (q--) {
		int u, v; cin >> u >> v >> k; --u; --v;
		vector<int> x, z;
		while (ch[u] != ch[v]) {
			if (!ancestor(head(u), v)) {
				z = t[ch[u]].query(pos[head(u)], pos[u]);
				u = p[head(u)];
			} else {
				assert(!ancestor(head(v), u));
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