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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    rep(e, 0, m) {
        int u, v, s;
        cin >> u >> v >> s;
        --u, --v;
        g[u].emplace_back(v, s);
        g[v].emplace_back(u, s);
    }

    constexpr int inf = 1e9 + 10;
    ll l = 0, r = inf;
    vector<ll> a(n), b(n);
    vector<bool> vis(n);

    auto upd_l = [&](ll x) { uax(l, x); };
    auto upd_r = [&](ll x) { uin(r, x); };

    auto dfs = [&](const auto& self, int u, int par) -> void {
        vis[u] = true;
        if (b[u] > 0)
            upd_l(-a[u]);
        else
            upd_r(+a[u]);

        for (auto [v, s] : g[u]) {
            if (v == par) continue;
            if (vis[v]) {
                const auto p = a[u] + a[v];
                const auto q = b[u] + b[v];
                if (q == 0) {
                    if (p != s) upd_r(-1);
                } else {
                    if ((s - p) % q != 0)
                        upd_r(-1);
                    else
                        upd_l((s - p) / q - 1), upd_r((s - p) / q + 1);
                }
            } else {
                a[v] = s - a[u];
                b[v] = -b[u];
                self(self, v, u);
            }
        }
    };
    a[0] = 0;
    b[0] = +1;
    dfs(dfs, 0, 0);

    /*
    cerr << '\n';
    rep(u, 0, n) cerr << a[u] << ' ' << b[u] << '\n';
    */

    cout << max(0ll, r - l - 1) << '\n';
}
