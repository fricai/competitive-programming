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

const int N = 1 << 17;
vector<int> g[N];
int a[N][2];
ll dp[N][2];

void dfs(int u) {
	for (int v : g[u]) {
		g[v].erase(find(all(g[v]), u));
		dfs(v);
	}
	
	for (auto b : {0, 1}) {
		dp[u][b] = 0;
		for (auto v : g[u]) {
			ll cur = 0;

			for (auto c : {0, 1})
				uax(cur, abs(a[u][b] - a[v][c]) + dp[v][c]);
			
			dp[u][b] += cur;
		}
	}
}

ll solve() {
	int n; cin >> n;
	rep(i, 0, n) cin >> a[i][0] >> a[i][1], g[i].clear();
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	return max(dp[0][0], dp[0][1]);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << "\n";
}