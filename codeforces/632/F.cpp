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

const int N = 2500 + 5, inf = 1e9;
int a[N][N];
pair<int, int> s[N]; 
vector<int> g[N];

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

    s[0] = {0, n};
    fill_n(s + 1, n, pair(inf, n));
    rep(i, 0, n) {
        int u = n;
        rep(v, 0, n)
            if (!vis[v] && s[v].first < s[u].first)
                u = v;
        vis[u] = 1;
        int v = s[u].second;
        if (v < n) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        rep(v, 0, n) if (a[u][v] < s[v].first) s[v] = {a[u][v], u};
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