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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
vector<int> g[N];
bool vis[N];

bool dfs(int u, int dep) {
	if (u == 0) return 1;
	vis[u] = 1;
	if (dep) {
		for (int v : g[u])
			if (!vis[v] && dfs(v, dep - 1))
				return 1;
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	rep(e, 0, m) {
		int u, v;
		cin >> u >> v;
		--u; --v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	cout << (dfs(n - 1, 2) ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
}