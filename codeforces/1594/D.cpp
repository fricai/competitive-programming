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

int solve() {
	int n, m; cin >> n >> m;
	vector<vector<pair<int, bool>>> g(n);
	rep(e, 0, m) {
		int u, v; string c; cin >> u >> v >> c; --u; --v;
		bool col = c == "imposter";
		g[u].emplace_back(v, col);
		g[v].emplace_back(u, col);
	}

	int count[2];
	vector<short> col(n, -1);
	auto dfs = [&](const auto& self, int u, bool b) -> bool {
		if (col[u] != -1) {
			return col[u] == b;
		}
		col[u] = b;
		++count[b];
		for (auto [v, s] : g[u]) {
			if (!self(self, v, b ^ s)) {
				return false;
			}
		}
		return true;
	};

	int ans = 0;
	rep(u, 0, n) {
		if (col[u] != -1)
			continue;
		count[0] = count[1] = 0;
		if (!dfs(dfs, u, 0))
			return -1;;
		ans += max(count[0], count[1]);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
