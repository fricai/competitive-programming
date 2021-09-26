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

	vector<int> s(n, 1);
	vector<ll> sum(n);
	auto init = [&](const auto &self, int u, int dep) -> void {
		sum[0] += dep;
		s[u] = 1;
		for (auto v : g[u]) {
			g[v].erase(find(all(g[v]), u));
			self(self, v, dep + 1);
			s[u] += s[v];
		}
	};
	init(init, 0, 0);

	auto dfs = [&](const auto &self, int u) -> void {
		for (auto v : g[u]) {
			sum[v] = sum[u] + (n - s[v]) - s[v];
			self(self, v);
		}
	};
	dfs(dfs, 0);

	for (auto x : sum)
		cout << x << '\n';
}
