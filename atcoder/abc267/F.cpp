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

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    rep(e, 1, n) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<array<int, 2>> furthest(n);
    {
        constexpr int inf = 2e5 + 20;
        vector<array<int, 3>> mx(n), mx2(n);
        auto init = [&](const auto& self, int u, int p) -> void {
            array<array<int, 3>, 3> tmp{{{-inf, -1, -1}, {-inf, -1, -1}, {0, u, u}}};
            for (auto v : g[u]) {
                if (v == p) continue;
                self(self, v, u);
                tmp[0] = {1 + mx[v][0], mx[v][1], v};
                sort(tmp.begin(), tmp.end());
            }
            mx[u] = tmp[2];
            mx2[u] = tmp[1];
        };
        init(init, 0, 0);

        auto reroot = [&](const auto& self, int u, int p) -> void {
            furthest[u] = {mx[u][0], mx[u][1]};
            for (auto v : g[u]) {
                if (v == p) continue;
                auto init_mx_v = mx[v];
                auto init_mx2_v = mx2[v];

                array<array<int, 3>, 3> tmp;
                tmp[0] = mx[v];
                tmp[1] = mx2[v];
                if (mx[u][2] != v)
                    tmp[2] = {1 + mx[u][0], mx[u][1], u};
                else
                    tmp[2] = {1 + mx2[u][0], mx2[u][1], u};
                sort(tmp.begin(), tmp.end());
                mx[v] = tmp[2];
                mx2[v] = tmp[1];

                self(self, v, u);

                mx[v] = init_mx_v;
                mx2[v] = init_mx2_v;
            }
        };
        reroot(reroot, 0, 0);
    }

    constexpr int B = 18;
    array<vector<int>, B> p;
    vector<int> dep(n);
    {
        p[0].resize(n);
        auto init = [&](const auto& self, int u) -> void {
            for (auto v : g[u]) {
                if (v == p[0][u]) continue;
                dep[v] = dep[u] + 1;
                p[0][v] = u;
                self(self, v);
            }
        };
        init(init, 0);

        rep(j, 0, B - 1) {
            p[j + 1].resize(n);
            rep(u, 0, n) p[j + 1][u] = p[j][p[j][u]];
        }
    }

    auto k_th_anc = [&](int u, int k) -> int {
        rep(j, 0, B) if (k >> j & 1) u = p[j][u];
        return u;
    };
    auto lca = [&](int u, int v) -> int {
        if (dep[u] < dep[v]) swap(u, v);
        u = k_th_anc(u, dep[u] - dep[v]);
        if (u == v) return u;
        per(j, 0, B) if (p[j][u] != p[j][v]) u = p[j][u], v = p[j][v];
        return p[0][u];
    };

    int q;
    cin >> q;
    while (q--) {
        int u, k;
        cin >> u >> k;
        --u;
        if (k > furthest[u][0]) {
            cout << "-1\n";
        } else {
            auto v = furthest[u][1];
            auto w = lca(u, v);
            if (k <= dep[u] - dep[w])
                cout << k_th_anc(u, k) + 1 << '\n';
            else
                cout << k_th_anc(v, (dep[v] - dep[w]) - (k - (dep[u] - dep[w]))) + 1 << '\n';
        }
    }
}
