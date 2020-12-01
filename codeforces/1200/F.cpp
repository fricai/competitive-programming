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

const int N = 1 << 10, LCM = 2520, NC = N * LCM;
int dp[NC], k[N], nxt[NC], col[NC];
vector<int> g[N];

int get(int n, int k) { return n * LCM + k; }
int unget(int x) { return x / LCM; }
int mod(int x) { x %= LCM; return x + (x < 0 ? LCM : 0); }

void dfs(int u) {
	col[u] = 1;
	if (col[nxt[u]] == 0) dfs(nxt[u]);
	if (col[nxt[u]] == 1) {
		vector<int> cycle = {unget(u)};
		for (int v = nxt[u]; v != u; v = nxt[v]) cycle.push_back(unget(v));
		sort(all(cycle)); dp[u] = unique(all(cycle)) - begin(cycle);
		for (int v = nxt[u]; v != u; v = nxt[v]) dp[v] = dp[u], col[v] = 2;
	}
	dp[u] = dp[nxt[u]];
	col[u] = 2;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) { cin >> k[i]; k[i] = mod(k[i]); }
	rep(i, 0, n) {
		int m; cin >> m; g[i].resize(m);
		for (int &x : g[i]) cin >> x, --x;
	}

	rep(u, 0, n) {
		rep(c, 0, LCM) {
			int r = mod(c + k[u]);
			nxt[get(u, c)] = get(g[u][r % sz(g[u])], r);
		}
	}
	rep(u, 0, n * LCM) if (!col[u]) dfs(u);

	int q; cin >> q;
	while (q--) {
		int u, y; cin >> u >> y; --u;
		cout << dp[get(u, mod(y))] << '\n';
	}
}