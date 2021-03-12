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

const int N = 150000 + 20, A = 27;
vector<int> g[N], h[N];
int c[N], p[N], dp[N][A], d[N], nxt[N], f[N][A], down[N], dep[N];

// f[u][a] = number of characters a on the path from u to nxt[u]

int failing = 0;
bool fail(int u) {
	ll s = 0;
	rep(c, 1, A) s += dp[u][c];
	return s > dep[u];
}

void dfs(int u) {
	for (int v : g[u]) {
		dfs(v);
		rep(c, 1, A) ckmax(dp[u][c], dp[v][c]);
		ckmax(dp[u][c[v]], dp[v][c[v]] + 1);
		ckmax(dep[u], 1 + dep[v]);
	}
	failing += fail(u);
}

void update(int u) {
	while (u != 0) {
		u = nxt[u];
		failing -= fail(u);
		rep(c, 1, A) dp[u][c] = 0;
		for (int v : h[u])
			rep(c, 1, A) ckmax(dp[u][c], dp[v][c] + f[v][c]);
		failing += fail(u);
	}
}

int hsh(char k) { return k == '?' ? 0 : k - 'a' + 1; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	
	rep(u, 1, n) {
		char k;
		cin >> p[u] >> k; --p[u];
		c[u] = hsh(k);
		d[u] = d[p[u]] + 1;
		g[p[u]].push_back(u);
	}

	int D = -1;
	rep(u, 0, n) {
		if (g[u].empty()) {
			if (D < 0) D = d[u];
			else if (D != d[u]) {
				while (q--) cout << "Fou\n";
				return 0;
			}
		}
	}

	dfs(0);
	rep(u, 1, n) {
		if (p[u] == 0 || sz(g[p[u]]) > 1) nxt[u] = p[u];
		else {
			nxt[u] = nxt[p[u]];
			rep(c, 0, A) f[u][c] = f[p[u]][c];
		}
		if (sz(g[u]) != 1) {
			down[u] = u;
			h[nxt[u]].push_back(u);
		}
		++f[u][c[u]];
	}
	per(u, 0, n) if (sz(g[u]) == 1) down[u] = down[g[u][0]];

	while (q--) {
		int u; char k; cin >> u >> k; --u;
		int v = down[u];
		--f[v][c[u]];
		c[u] = hsh(k);
		++f[v][c[u]];
		update(v);

		if (failing) cout << "Fou\n";
		else {
			ll s = 0, ans = 0;
			rep(c, 1, A) s += dp[0][c];
			rep(c, 1, A) ans += c * (D - s + dp[0][c]);
			cout << "Shi " << ans << '\n';
		}
	}
}