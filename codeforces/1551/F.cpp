#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100 + 10, M = 1e9 + 7;
vector<vector<int>> g;
int d[N][N]; // d[i][j] = number of vertices in the subtree of i which are at distance j from root
int dp[N][N];

int n;
void dfs(int u, int p, int dep) {
	fill_n(d[u], n, 0);
	++d[u][dep];
	for (int v : g[u]) {
		if (v == p) continue;
		dfs(v, u, dep + 1);
		rep(j, 0, n) d[u][j] += d[v][j]; 
	}
}

int solve() {
	int k; cin >> n >> k;
	g.clear();
	g.resize(n);
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if (k == 2)
		return 1ll * n * (n - 1) / 2 % M;

	int ans = 0;
	rep(u, 0, n) {
		if (sz(g[u]) < k)
			continue;
		
		dfs(u, -1, 0);
		
		// dp[i][j] = number of ways to choose j vertices from the first i elements
		
		int m = sz(g[u]);
		rep(dep, 0, n) {
			rep(i, 0, m + 1)
				fill_n(dp[i], n, 0);
			
			dp[0][0] = 1;
			for (int i = 1; i <= m; ++i) {
				int v = g[u][i - 1];
				dp[i][0] = dp[i - 1][0];
				for (int j = 1; j <= i; ++j)
					dp[i][j] = (1ll * dp[i - 1][j - 1] * d[v][dep] % M + dp[i - 1][j]) % M;
			}
			ans = (ans + dp[m][k]) % M;
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}