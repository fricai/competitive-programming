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

const int N = 1 << 19;
vector<int> g[N];
bool vis[N];
int node_cnt, edge_cnt;

void dfs(int u) {
    ++node_cnt;
    vis[u] = 1;
    for (int v : g[u]) {
        ++edge_cnt;
        if (!vis[v]) dfs(v);
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n; cin >> n;
    rep(i, 0, n) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    rep(u, 1, N) {
        if (g[u].empty() || vis[u]) continue;
        node_cnt = edge_cnt = 0;
        dfs(u);
        edge_cnt /= 2;
        ans += min(edge_cnt, node_cnt);
    }
    cout << ans;
}