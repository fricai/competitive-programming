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

const int N = 1 << 18, M = 998244353;
int f[N];
vector<int> g[N];
bool vis[N];

void dfs(int u) {
	vis[u] = 1;
	for (int v : g[u])
		if (!vis[v]) dfs(v);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for (int u = 1; u <= n; ++u) {
		int p; cin >> p;
		g[p].push_back(u);
		g[u].push_back(p);
	}
	
	int ans = 1;
	for (int u = 1; u <= n; ++u) {
		if (vis[u]) continue;
		dfs(u);
		ans += ans;
		if (M <= ans) ans -= M;
	}
	--ans; if (ans < 0) ans += M;
	cout << ans << '\n';
}