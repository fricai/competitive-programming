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

struct eq_solver {
	int n;
	vector<vector<pair<int, bool>>> g;
	vector<int> col;

	eq_solver(int n) : n{n}, g(n), col(n, -1) { }
	void add(int x, int y, bool b) {
		// add the constraint that x ^ y = b
		g[x].emplace_back(y, b);
		g[y].emplace_back(x, b);
	}

	bool solve() {
		auto dfs = [&](const auto &self, int u, bool b) -> bool {
			if (col[u] != -1)
				return col[u] == b;
			col[u] = b;
			for (auto [v, w] : g[u])
				if (!self(self, v, b ^ w))
					return false;
			return true;
		};

		rep(u, 0, n) {
			if (col[u] == -1 && !dfs(dfs, u, 0))
				return false;
		}
		return true;
	}
};

void solve() {
	int n, m; cin >> n >> m;

	vector<vector<pair<int, int>>> g(n);
	eq_solver s(n);
	vector<tuple<int, int, int>> edges(n - 1);

	for (auto &[u, v, x] : edges) {
		cin >> u >> v >> x; --u; --v;
		g[v].push_back({u, x});
		g[u].push_back({v, x});
		if (x != -1) s.add(u, v, __builtin_popcount(x) & 1);
	}
	rep(i, 0, m) {
		int u, v, p; cin >> u >> v >> p; --u; --v;
		s.add(u, v, p);
	}

	if (!s.solve()) {
		return void(cout << "NO\n");
	}

	cout << "YES\n";
	auto init = [&](const auto &self, int u, int p, int cur) -> void {
		for (auto [v, x] : g[u]) {
			if (v == p)
				continue;
			cout << u + 1 << ' ' << v + 1 << ' ';

			int nxt = -1;
			if (x != -1) {
				cout << x << '\n';
				nxt = cur ^ x;
			} else {
				cout << (cur ^ s.col[v]) << '\n';
				nxt = s.col[v];
			}
			self(self, v, u, nxt);
		}
	};
	init(init, 0, 0, 0);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
