#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int B = 20;

vector<int> nxt;
int head(int u) { return nxt[u] == u ? u : nxt[u] = head(nxt[u]); }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	vector<int> e(n);
	for (auto &x : e) {
		cin >> x;
	}

	vector<vector<pair<int, int>>> g(n);

	vector<tuple<int, int, int, int>> edges(n - 1);
	for (auto &[c, u, v, t] : edges) {
		cin >> u >> v >> c >> t;
		--u; --v;

		g[u].emplace_back(v, t);
		g[v].emplace_back(u, t);
	}

	vector p(n, vector(B, 0));
	vector w(n, vector(B, 0));
	vector dep(n, 0);
	auto dfs = [&](const auto &self, int u) -> void {
		for (auto [v, t] : g[u]) {
			if (p[u][0] == v)
				continue;
			dep[v] = dep[u] + 1;
			w[v][0] = t;
			p[v][0] = u;
			self(self, v);
		}
	};
	dfs(dfs, 0);

	rep(j, 0, B - 1) {
		rep(u, 0, n) {
			p[u][j + 1] = p[p[u][j]][j];
			w[u][j + 1] = max(w[u][j], w[p[u][j]][j]);
		}
	}

	auto get_max = [&](int u, int v) -> int {
		if (dep[u] > dep[v]) // u is above v
			swap(u, v);

		int cur = 0;
		per(j, 0, B) {
			if (dep[p[v][j]] < dep[u])
				continue;
			uax(cur, w[v][j]);
			v = p[v][j];
		}

		if (u == v)
			return cur;

		per(j, 0, B) {
			if (p[v][j] == p[u][j])
				continue;
			uax(cur, max(w[u][j], w[v][j]));
			v = p[v][j];
			u = p[u][j];
		}
		return max({cur, w[u][0], w[v][0]});
	};

	nxt.resize(n);
	iota(all(nxt), 0);

	vector<int> tol(n), mxi(n);
	iota(all(mxi), 0);
	auto enj = e;
	auto merge = [&](int u, int v) {
		u = head(u); v = head(v);

		assert(u != v);

		nxt[v] = u;
		if (enj[u] == enj[v]) {
			tol[u] = max({tol[u], tol[v], get_max(mxi[u], mxi[v])});
		} else if (uax(enj[u], enj[v])) {
			mxi[u] = mxi[v];
			tol[u] = tol[v];
		}
	};

	sort(rall(edges));
	vector<tuple<int, int, int>> tours(q);
	int idx = 0;
	for (auto &[v, x, i] : tours) {
		cin >> v >> x; --x;
		i = idx++;
	}
	sort(rall(tours));

	vector<pair<int, int>> ans(q);

	int i = 0;
	for (auto [v, x, idx] : tours) {
		while (i < sz(edges) && get<0>(edges[i]) >= v) {
			merge(get<1>(edges[i]), get<2>(edges[i]));
			++i;
		}

		int u = head(x);
		ans[idx] = {enj[u], max(get_max(mxi[u], x), tol[u])}; 
	}

	for (auto [a, b] : ans) {
		cout << a << ' ' << b << '\n';
	}
}
