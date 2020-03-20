#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)
#define ff first
#define ss second

using ll = int64_t;

const int M = 1e9 + 7;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

constexpr int N = 1 << 17;
vector<int> g[N];
ll dp[N][2];

void dfs(int u, int p) {
	dp[u][0] = dp[u][1] = 1;
	trav(v, g[u]) {
		if (v == p) continue;
		dfs(v, u);
		dp[u][0] = 1ll * dp[u][0] * (dp[v][0] + dp[v][1]) % M;
		dp[u][1] = 1ll * dp[u][1] * dp[v][0] % M;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].eb(v); g[v].eb(u);
	}
	dfs(0, 0);
	cout << (dp[0][0] + dp[0][1]) % M;
}