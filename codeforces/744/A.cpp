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

const int N = 1 << 10;
vector<int> g[N];
bool vis[N], gov[N];

int c;
bool dfs(int u) {
	++c; vis[u] = 1;
	bool res = gov[u];
	for (int v : g[u])
		if (!vis[v])
			res |= dfs(v);
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k; cin >> n >> m >> k;
	rep(i, 0, k) {
		int x; cin >> x;
		gov[x] = 1;
	}
	rep(e, 0, m) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int oth = 0;
	vector<int> nu;
	for (int u = 1; u <= n; ++u) {
		if (vis[u]) continue;
		c = 0;
		if (dfs(u)) nu.push_back(c);
		else oth += c;
	}
	sort(all(nu));
	oth += nu.back();
	nu.pop_back();
	nu.push_back(oth);
	int ans = -m;	
	for (auto x : nu) ans += x * (x - 1) / 2;
	cout << ans;
}