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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	vector<vector<int>> h(n), g(n);
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		h[u].push_back(v);
		h[v].push_back(u);
	}

	vector<bool> vis(n);
	auto init = [&](const auto &self, int u) -> void {
		vis[u] = true;
		for (auto v : h[u]) {
			if (vis[v])
				continue;
			g[u].push_back(v);
			g[v].push_back(u);
			self(self, v);
		}
	};
	init(init, 0);

	vector<vector<int>> paths;
	vector<bool> occ(n);

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b; --a; --b;
		occ[a] = !occ[a];
		occ[b] = !occ[b];

		vector<int> path;
		auto get_path = [&](const auto &self, int u, int p) -> bool {
			path.push_back(u);
			if (u == b)
				return true;
			for (auto v : g[u]) {
				if (v != p && self(self, v, u))
					return true;
			}
			path.pop_back();
			return false;
		};

		get_path(get_path, a, -1);
		paths.push_back(path);
	}

	int ans = 0;
	rep(u, 0, n) ans += occ[u];
	if (ans > 0)
		return cout << "NO\n" << ans / 2 << '\n', 0;

	cout << "YES\n";
	for (auto &path : paths) {
		cout << sz(path) << '\n';
		for (auto x : path) {
			cout << x + 1 << ' ';
		}
		cout << '\n';
	}
}
