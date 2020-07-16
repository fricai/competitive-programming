#include <algorithm>
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

int k = K;
vector<int> operator+(const vector<int> &a, const vector<int> &b) {
	vector<int> v(sz(a) + sz(b));
	merge(all(a), all(b), begin(v));
	if (k < sz(v)) v.resize(k);
	return v;
}

int lo, hi;
struct T {
	int n; vector<int> nodes;
	vector<vector<int>> t;
	void init() {
		n = sz(nodes);
		int sz = 1; while (sz < n) sz <<= 1;
		t.resize(2 * sz); build(1, 0, n);
	}
	void build(int v, int l, int r) {
		if (r - l == 1) return swap(t[v], z[nodes[l]]);
		int m = l + r >> 1;
		build(v << 1, l, m); build(v << 1|1, m, r);
		t[v] = t[v << 1] + t[v << 1|1];
	}
	vector<int> query(int v, int l, int r) {
		if (r <= lo || hi <= l) return { };
		if (lo <= l && r <= hi) {
			if (sz(t[v]) <= k) return {all(t[v])};
			return {begin(t[v]), begin(t[v]) + k};
		}
		int m = l + r >> 1;
		return query(v << 1, l, m) + query(v << 1|1, m, r);
	}
	vector<int> query(int l, int r) {
		if (l > r) swap(l, r); lo = l; hi = r + 1;
		return query(1, 0, n);
	}
}; vector<T> t;

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
	rep(i, 0, m) { int x; cin >> x; if (sz(z[--x]) < K) z[x].eb(i + 1); }
	dfs(0, 0); trav(v, t) v.init();
	while (q--) {
		int u, v; cin >> u >> v >> k; --u; --v;
		vector<int> x;
		while (ch[u] != ch[v]) {
			if (!ancestor(head(u), v)) {
				x = x + t[ch[u]].query(pos[head(u)], pos[u]);
				u = p[head(u)];
			} else {
				x = x + t[ch[v]].query(pos[head(v)], pos[v]);
				v = p[head(v)];
			}
		}
		x = x + t[ch[u]].query(pos[u], pos[v]);

		cout << sz(x) << ' '; trav(z, x) cout << z << ' '; cout << '\n';
	}
}