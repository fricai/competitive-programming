#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 19;
vector<int> g[N];
bool vis[N];
int d[N];
vector<int> path;

int n;
bool dfs(int u) {
	if (d[u] >= (n + 1) / 2) return path.eb(u), true;
	vis[u] = true;
	for (int v : g[u]) {
		if (vis[v]) continue;
		d[v] = d[u] + 1;
		if (dfs(v)) return path.eb(u), true;
	}
	return false;
}

void solve() {
	int m; cin >> n >> m;
	rep(u, 0, n) g[u].clear(), vis[u] = false;
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].eb(v); g[v].eb(u);
	}
	path.clear();
	if (dfs(0)) {
		cout << "PATH\n";
		cout << sz(path) << '\n';
		for (int v : path) cout << v + 1 << ' ';
		cout << '\n';
	} else {
		vector<vector<int>> s(n);
		rep(u, 0, n) s[d[u]].eb(u);
		vector<pair<int, int>> match;
		for (auto &v : s)
			for (int i = 0; i + 1 < sz(v); i += 2)
				match.eb(v[i], v[i + 1]);
		cout << "PAIRING\n";
		cout << sz(match) << '\n';
		for (auto [x, y] : match) cout << x + 1 << ' ' << y + 1 << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}