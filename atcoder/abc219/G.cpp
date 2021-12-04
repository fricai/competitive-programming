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

constexpr int B = 900;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >> n >> m >> q;
	vector<vector<int>> g(n);
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (auto &adj : g) {
		sort(all(adj), [&](int x, int y) {
				return sz(g[x]) > sz(g[y]);
				});
	}

	vector<int> val(n);
	iota(all(val), 1);

	vector<pair<int, int>> lazy(n);
	vector<int> lst(n);

	auto fix = [&](int u) {
		for (int j = 0; j < sz(g[u]); ++j) {
			int v = g[u][j];
			if (sz(g[v]) <= B) {
				break;
			}
			if (lazy[v].first > lst[u]) {
				tie(lst[u], val[u]) = lazy[v];
			}
		}
	};

	for (int i = 1; i <= q; ++i) {
		int u; cin >> u; --u;
		fix(u);
		if (sz(g[u]) <= B) {
			for (auto v : g[u]) {
				val[v] = val[u];
				lst[v] = i;
			}
		} else {
			lazy[u] = {i, val[u]};
		}
	}

	rep(u, 0, n) {
		fix(u);
		cout << val[u] << ' ';
	}
	cout << '\n';
}
