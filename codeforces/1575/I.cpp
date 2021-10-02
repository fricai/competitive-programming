#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using vi = vector<int>;
template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

struct segtree {
	int n;
	vector<ll> t;
	segtree(int n) : n{n}, t(n + n, 0) { }
	ll query(int l, int r) {
		ll res = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) res += t[l++];
			if (r&1) res += t[--r];
		}
		return res;
	}
	void modify(int p, ll v) {
		for (t[p += n] = v; p > 1; p >>= 1)
			t[p>>1] = t[p] + t[p^1];
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	vector<int> a(n);
	rep(i, 0, n) cin >> a[i], a[i] = abs(a[i]);

	vector<vector<int>> g(n);
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> in(n), out(n); int timer = 0;
	auto dfs = [&](const auto& self, int u, int p) -> void {
		in[u] = timer++;
		for (auto v : g[u])
			if (v != p)
				self(self, v, u);
		out[u] = timer++;
	};
	dfs(dfs, 0, 0);

	segtree t(2 * n);
	rep(u, 0, n) {
		t.modify(in[u], +a[u]);
		t.modify(out[u], -a[u]);
	}

	LCA l(g);
	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int u, c; cin >> u >> c; --u;
			c = abs(c);
			t.modify(in[u], +c);
			t.modify(out[u], -c);
			a[u] = c;
		} else {
			int u, v; cin >> u >> v; --u; --v;
			int w = l.lca(u, v);
			auto p = t.query(0, in[u] + 1);
			auto q = t.query(0, in[v] + 1);
			auto r = t.query(0, in[w] + 1);

			auto d = 2 * (p + q - 2 * r) + 2 * a[w] - a[u] - a[v];

			cout << d << '\n';
		}
	}
}
