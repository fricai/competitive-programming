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

const int B = 17, N = 1 << B, M = 1e9 + 7;
int p[B][N];
ll x[N], y[B][N];
vector<int> g[N];
ll ans[N], d[N];

void init(int u) {
	for (int v : g[u]) {
		g[v].erase(find(all(g[v]), u));
		p[0][v] = u;
		d[v] = d[u] + 1;
		init(v);
	}
}

void dfs(int u) {
	if (x[u] == 0) ans[u] = ans[p[0][u]];
	else {
		ans[u] = 0;
		ll z = x[u];
		int v = u, pre = d[u];

		// cerr << u << ": ";
		while (v != 0) {
			// cerr << v << ' ';
			assert(z != 0);
			per(j, 0, B) if (y[j][v] % z == 0) v = p[j][v];
			(ans[u] += z % M * (pre - d[v] + 1)) %= M;
			// cerr << v << ' ' << z << ' ' << (pre - d[v] + 1) << ' '<< z << "; ";
			v = p[0][v];
			pre = d[v];
			z = gcd(z, x[v]);
		}
	}
	for (int v : g[u]) dfs(v);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	rep(e, 1, n) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	init(1);

	rep(j, 1, B) for (int u = 1; u <= n; ++u) p[j][u] = p[j - 1][p[j - 1][u]];
	for (int u = 1; u <= n; ++u) y[0][u] = gcd(x[p[0][u]], x[u]);

	rep(j, 1, B) for (int u = 1; u <= n; ++u) y[j][u] = gcd(y[j - 1][p[j - 1][u]], y[j - 1][u]);
	dfs(1);
	// for (int u = 1; u <= n; ++u) {
	// 	rep(j, 0, B) cerr << y[j][u] << ' ';
	// 	cerr << '\n';
	// }

	ll fin = 0;
	for (int u = 1; u <= n; ++u) fin = (fin + ans[u]) % M;
	// cerr << '\n';
	cout << fin;
	// << '\n';
}