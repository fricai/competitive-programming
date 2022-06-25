#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i{a}; i < (b); ++i)
#define per(i, a, b) for (auto i{b}; i-- > (a);)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template <class T>
bool uin(T& a, const T& b) {
    return a > b ? a = b, true : false;
}
template <class T>
bool uax(T& a, const T& b) {
    return a < b ? a = b, true : false;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;

    vector eq(n, vector(n, vector(n, true)));
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            string s;
            cin >> s;
            rep(k, 0, n) eq[i][j][k] = eq[j][i][k] = s[k] == '1';
        }
    }
    // eq[i][j][k] <=> d(i, k) = d(j, k)
    // eq[i][i][k] <=> d(i, k) = d(i, k)

    auto get_eq = [](auto& g) {
        const int n = g.size();
        constexpr int inf = 1e9;
        vector d(n, vector(n, inf));
        rep(u, 0, n) d[u][u] = 0;
        rep(u, 0, n) for (auto v : g[u]) d[u][v] = 1;
        rep(w, 0, n) rep(u, 0, n) rep(v, 0, n) d[u][v] = min(d[u][v], d[u][w] + d[w][v]);

        vector eq(n, vector(n, vector(n, false)));
        rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) eq[i][j][k] = d[i][k] == d[j][k];
        return eq;
    };

    rep(i, 1, n) {
        // (0, i) is an edge
        vector<vector<int>> g(n);
        vector<bool> vis(n);
        auto dfs = [&](const auto& self, int u, int p) -> void {
            if (vis[u]) return;
            vis[u] = true;
            rep(v, 0, n) if (eq[v][p][u]) g[u].push_back(v);
            for (auto v : g[u]) {
                if (v == p) continue;
                self(self, v, u);
            }
        };
        rep(u, 1, n) if (eq[u][i][0]) {
            g[0].push_back(u);
            dfs(dfs, u, 0);
        }
        assert(vis[i]);

        int edges = 0;
        rep(u, 0, n) edges += sz(g[u]);
        if (edges != 2 * (n - 1)) continue;
        if (eq != get_eq(g)) continue;
        cout << "Yes\n";
        rep(u, 0, n) for (auto v : g[u]) if (u < v) cout << u + 1 << ' ' << v + 1 << '\n';
        return;
    }
    cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
