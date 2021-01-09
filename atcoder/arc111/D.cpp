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

const int N = 1 << 7, M = N * N / 2;
vector<int> g[N];
short dir[M];
int c[N], a[M], b[M];
bool vis[N];

void dfs(int u) {
    vis[u] = 1;
    for (int e : g[u]) {
        if (dir[e]) continue;
        int v = a[e] ^ b[e] ^ u;
        dir[e] = 1 - 2 * (u != a[e]);
        if (!vis[v]) dfs(v);
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    rep(e, 0, m) {
        cin >> a[e] >> b[e]; --a[e]; --b[e];
        g[a[e]].push_back(e);
        g[b[e]].push_back(e);
    }
    rep(u, 0, n) cin >> c[u];
    rep(e, 0, m) {
        if (c[a[e]] > c[b[e]]) dir[e] = +1;
        if (c[a[e]] < c[b[e]]) dir[e] = -1;
    }

    rep(u, 0, n) if (!vis[u]) dfs(u);
    rep(e, 0, m) cout << (dir[e] > 0 ? "->" : "<-") << '\n';
}