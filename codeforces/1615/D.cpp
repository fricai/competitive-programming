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

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> t(n);
	vector<tuple<int, int, int>> edges(n - 1);

	{
	int e = 0;
	for (auto &[x, y, v] : edges) {
		cin >> x >> y >> v;
		--x; --y;
		t[x].push_back(e);
		t[y].push_back(e);
		++e;
	}
	}

	vector<int> p(n, -1);
	auto init = [&](const auto &self, int u) -> void {
		for (auto e : t[u]) {
			auto [a, b, x] = edges[e];
			int v = a ^ b ^ u;
			t[v].erase(find(all(t[v]), e));
			p[v] = u;
			self(self, v);
		}
	};
	init(init, 0);

	vector<vector<pair<int, bool>>> g(n);
	auto add_edge = [&](int u, int v, int x) {
		g[u].emplace_back(v, x);
		g[v].emplace_back(u, x);
	};

	vector<int> val(n, -1);
	for (auto [x, y, v] : edges) {
		if (x != p[y]) swap(x, y);
		val[y] = v;
		if (v != -1) {
			add_edge(x, y, __builtin_popcount(v) & 1);
		}
	}

	rep(i, 0, m) {
		int a, b, p; cin >> a >> b >> p; --a; --b;
		add_edge(a, b, p);
	}

	vector<short> col(n, -1);
	auto bip = [&](const auto &self, int u, bool par) -> bool {
		if (col[u] != -1) return col[u] == par;
		col[u] = par;
		for (auto [v, w] : g[u]) {
			if (!self(self, v, par ^ w))
				return false;
		}
		return true;
	};

	rep(u, 0, n) {
		if (col[u] != -1)
			continue;
		if (!bip(bip, u, 0)) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
	int x[2] = {3, 1};
	rep(u, 1, n) {
		cout << p[u] + 1 << ' ' << u + 1 << ' ';
		if (val[u] != -1)
			cout << val[u];
		else {
			cout << x[col[u] ^ col[p[u]]];
		}
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
