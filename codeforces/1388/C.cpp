#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 17;
vector<int> g[N];
ll h[N], p[N], q[N], d[N], par[N];

void init_dfs(int u) {
	q[u] = p[u];
	trav(v, g[u]) {
		g[v].erase(find(all(g[v]), u));
		init_dfs(v);
		q[u] += q[v];
	}
	d[u] = (q[u] - h[u]) / 2;
}

bool solve() {
	int n, m; cin >> n >> m;
	rep(i, 0, n) cin >> p[i];
	rep(i, 0, n) cin >> h[i];
	rep(u, 0, n) g[u].clear();
	rep(i, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].eb(v); g[v].eb(u);
	}
	init_dfs(0); assert(q[0] == m);
	rep(u, 0, n) if (d[u] < 0 || d[u] > q[u] || (q[u] - h[u]) % 2) return false;
	rep(u, 0, n) {
		ll sum = 0;
		trav(v, g[u]) sum += d[v];
		if (p[u] + sum < d[u]) return false;
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}