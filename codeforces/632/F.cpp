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

const int N = 2500 + 5;
int a[N][N];
pair<int, pair<int, int>> c[N * N];
vector<int> g[N];

int nxt[N];
int head(int u) { return nxt[u] != u ? nxt[u] = head(nxt[u]) : u; }
bool join(int u, int v) {
    u = head(u); v = head(v);
    if (u == v) return 0;
    return nxt[u] = v, 1;
}

bool vis[N];
bool dfs(int u, int p, int x) {
    vis[u] = 1;
    if (a[p][u] != x) return 1;
    for (int v : g[u])
        if (!vis[v] && dfs(v, p, max(x, a[u][v])))
            return 1;
    return 0;
}

bool solve() {
	int n; cin >> n;
	rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
	
	rep(i, 0, n) if (a[i][i] != 0) return 0;
	rep(i, 0, n) rep(j, 0, i) if (a[i][j] != a[j][i]) return 0;

    iota(nxt, nxt + n, 0);
	int m = 0;
	rep(i, 0, n) rep(j, 0, i) c[m++] = {a[i][j], {i, j}};
	sort(c, c + m);
    rep(e, 0, m) {
        auto [u, v] = c[e].second;
        if (join(u, v)) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    rep(u, 0, n) {
        fill_n(vis, n, 0);
        if (dfs(u, u, 0)) return 0;
    }
	return 1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << (solve() ? "MAGIC" : "NOT MAGIC");
}