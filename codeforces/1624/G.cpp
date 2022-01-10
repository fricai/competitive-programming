#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int B = 30;

int solve() {
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	rep(e, 0, m) {
		int u, v, w; cin >> u >> v >> w; --u; --v;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	int pattern = 0, mask = 0;
	per(i, 0, B) {
		mask |= 1 << i;

		vector<bool> vis(n);
		auto dfs = [&](const auto &self, int u) -> void {
			vis[u] = true;
			for (auto [v, w] : g[u]) {
				if (vis[v]) continue;
				if (((~w | pattern) & mask) == mask)
					self(self, v);
			}
		};

		dfs(dfs, 0);
		if (count(all(vis), true) < n) pattern |= 1 << i;
	}
	return pattern;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
