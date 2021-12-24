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

constexpr int inf = 1e9;


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<vector<int>> g(n);
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int leaves = 0;
	rep(u, 1, n) leaves += sz(g[u]) == 1;

	auto f = [&](ll x) { return x * (n - x); };
	if (k >= leaves) {
		cout << f(max(leaves, min(k, n / 2))) << '\n';
		return 0;
	}

	// pick k leaves such that the minimal subtree containing them is maxmized
	
	vector<int> p(n, -1), d(n), c(n);
	auto init = [&](const auto &self, int u) -> void {
		for (auto v : g[u]) {
			if (v == p[u])
				continue;
			p[v] = u;
			d[v] = d[u] + 1;
			self(self, v);
		}
	};
	init(init, 0);

	vector<int> ord(n);
	iota(all(ord), 0);
	sort(all(ord), [&](int x, int y) {
			return d[x] > d[y];
			});
	vector<bool> vis(n);
	for (auto u : ord) {
		if (u == 0 || sz(g[u]) > 1)
			continue;
		int &x = c[u];
		while (u >= 0 && !vis[u]) {
			vis[u] = true;
			++x;
			u = p[u];
		}
	}
	sort(all(ord), [&](int x, int y) {
			return c[x] > c[y];
			});

	int blocked = 0;
	rep(i, 0, k) blocked += c[ord[i]];
	cout << f(k) - f(min(n - blocked, n / 2)) << '\n';
}
