#include <bits/stdc++.h>
#include <atcoder/modint>

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

using mint = atcoder::modint998244353;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<vector<int>> g(n);
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	auto furthest = [&](int r) {
		int x = r, mx = 0;
		auto dfs = [&](const auto &self, int u, int p, int dep) -> void {
			if (uax(mx, dep))
				x = u;
			for (auto v : g[u])
				if (v != p)
					self(self, v, u, dep + 1);
		};
		dfs(dfs, r, r, 0);
		return pair(x, mx);
	};
	int x = furthest(0).first;
	auto [y, dia] = furthest(x);

	auto get_path = [&](int x, int y) {
		vector<int> path = {y};
		auto dfs = [&](const auto &self, int u, int p) -> bool {
			if (u == y)
				return true;
			for (auto v : g[u])
				if (v != p && self(self, v, u))
					return path.push_back(u), true;
			return false;
		};
		dfs(dfs, x, x);
		return path;
	};

	auto get_count = [&](int r, int block, int target) {
		int res = 0;
		auto dfs = [&](const auto &self, int u, int p, int dep) -> void {
			if (dep == target)
				++res;
			for (auto v : g[u]) {
				if (v != p)
					self(self, v, u, dep + 1);
			}
		};
		dfs(dfs, r, block, 0);
		return res;
	};

	auto path = get_path(x, y);

	if (dia & 1) {
		int s = path[sz(path) / 2 - 1], t = path[sz(path) / 2];

		mint p = get_count(s, t, dia / 2);
		mint q = get_count(t, s, dia / 2);

		cout << (p * q).val() << '\n';
	} else {
		int r = path[sz(path) / 2];
		vector<mint> opt;
		for (auto v : g[r])
			opt.push_back(get_count(v, r, dia / 2 - 1));

		for (auto x : opt)
			cerr << x.val() << ' ';
		cerr << '\n';

		mint ans = 1;
		for (auto x : opt)
			ans *= mint::raw(1) + x;
		--ans;
		for (auto x : opt)
			ans -= x;

		cout << ans.val() << '\n';
	}
}
