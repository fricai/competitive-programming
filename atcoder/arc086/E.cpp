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

using mint = atcoder::modint1000000007;
const mint zero = 0, one = 1, two = 2, half = one / two;

using state = array<mint, 3>;

state merge(const state &a, const state &b) {
	state c = {zero, zero, zero};
	for (int x = 0; x < 3; ++x) {
		for (int y = 0; y < 3; ++y) {
			c[min(x + y, 2)] += a[x] * b[y];
		}
	}
	return c;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> p(n + 1);
	vector<vector<int>> g(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		g[p[i]].push_back(i);
	}

	vector<deque<state>> dp(n + 1);
	for (int u = n; u >= 0; --u) {
		sort(all(g[u]), [&](int x, int y) {
				return sz(dp[x]) > sz(dp[y]);
				});

		int changes = 0;
		while (sz(g[u]) > 1) {
			int x = g[u].back(); g[u].pop_back();
			int y = g[u].back();

			changes = sz(dp[x]);
			rep(i, 0, changes) {
				dp[y][i] = merge(dp[x][i], dp[y][i]);
			}
		}
		if (!g[u].empty()) {
			dp[u] = move(dp[g[u][0]]);
		}
		rep(i, 0, changes) {
			dp[u][i][0] += dp[u][i][2];
			dp[u][i][2] = 0;
		}
		dp[u].push_front({half, half, zero});
	}

	mint ans = zero;
	for (auto x : dp[0]) {
		ans += x[1];
	}
	ans *= two.pow(n + 1);
	cout << ans.val() << '\n';
}
