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
	int n; cin >> n;
	vector<vector<int>> g(n);
	rep(u, 0, n) {
		int k; cin >> k;
		g[u].resize(k);
		for (auto &v : g[u])
			cin >> v, --v;
	}

	vector<int> dp(n, -1);
	auto cycle = [&](const auto &self, int u) -> bool {
		if (dp[u] == 0)
			return true;
		if (dp[u] > 0)
			return false;
		if (dp[u] < 0)
			dp[u] = 0;
		for (auto v : g[u])
			if (self(self, v))
				return true;
		dp[u] = 1;
		return false;
	};

	rep(u, 0, n)
		if (dp[u] == -1 && cycle(cycle, u))
			return -1;

	dp.assign(n, -1);
	
	auto f = [&](const auto &self, int u) -> int {
		if (dp[u] != -1)
			return dp[u];
		dp[u] = 1;
		for (auto v : g[u])
			uax(dp[u], (u < v) + self(self, v));
		return dp[u];
	};

	int ans = 0;
	rep(u, 0, n)
		uax(ans, f(f, u));
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
