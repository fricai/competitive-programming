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

	int n, m, k; cin >> n >> m >> k;

	vector<int> z(m);
	for (auto &x : z) cin >> x, --x;

	vector<vector<int>> g(n);
	vector<int> a(n - 1), b(n - 1);
	rep(e, 0, n - 1) {
		cin >> a[e] >> b[e]; --a[e]; --b[e];
		g[a[e]].push_back(e);
		g[b[e]].push_back(e);
	}

	vector<int> val(n - 1);
	auto color = [&](int s, int t) {
		auto dfs = [&](const auto &self, int u, int p) -> bool {
			if (u == t)
				return true;
			for (auto e : g[u])
				if (e != p && self(self, a[e] ^ b[e] ^ u, e))
					return ++val[e], true;
			return false;
		};
		dfs(dfs, s, -1);
	};

	rep(i, 1, m) color(z[i - 1], z[i]);
	int x = accumulate(all(val), 0);

	if (((k ^ x) & 1) || k < -x || k > x)
		return cout << "0\n", 0;

	k = (k + x) / 2;

	vector dp(2, vector<mint>(k + 1));
	dp[0][0] = 1;
	rep(e, 0, n - 1) {
		dp[~e & 1] = dp[e & 1];
		for (int i = val[e], j = 0; i <= k; ++i, ++j)
			dp[~e & 1][i] += dp[e & 1][j];
	}
	cout << dp[~n & 1][k].val() << '\n';
}
