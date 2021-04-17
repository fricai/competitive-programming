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

const int N = 1 << 18;
vector<int> g[N];

bool exists(int u, int v) { return binary_search(all(g[u]), v); }

int n;

struct dsu {
    int nxt[N];

    dsu(int n) { fill_n(nxt, n, -1); }
    int head(int u) { return nxt[u] < 0 ? u : nxt[u] = head(nxt[u]); }
    bool join(int u, int v) {
        u = head(u); v = head(v);
        if (u == v) return 0;
        return nxt[u] = v, 1;
    }
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int m; cin >> n >> m;

    int x = 0;
    vector<tuple<int, int, int>> edges;

    ll r = 1ll * n * (n - 1) / 2 - m;
    
    rep(e, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        
        x ^= w;
        
        edges.emplace_back(w, u, v);
    }

    rep(u, 0, n) sort(all(g[u]));

    queue<int> q;
    vector<int> unvisited(n);
    iota(all(unvisited), 0);

    dsu d(n), e(n);
    while (!unvisited.empty()) {
        q.push(unvisited.back());
        unvisited.pop_back();

        while (!q.empty()) {
            int u = q.front(); q.pop();
            vector<int> nxt;
            for (auto v : unvisited)
                if (exists(u, v)) nxt.push_back(v);
                else {
                    --r;
                    d.join(u, v);
                    q.push(v);
                }
            
            unvisited = move(nxt);
        }
    }
    
    if (r) x = 0;

    ll ans = 0;

    sort(all(edges));
    for (auto [w, u, v] : edges)
        if (d.join(u, v)) {
            ans += w;
            e.join(u, v);
        } else if (e.join(u, v))
            ckmin(x, w);
    cout << ans + x << '\n';
}