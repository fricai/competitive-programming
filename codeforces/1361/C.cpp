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

vector<int> eulerWalk(vector<vector<pair<int, int>>>& gr, int nedges, int src) {
    int n = sz(gr);
    vector<int> D(n), its(n), eu(nedges), ret;
    vector<pair<int, int>> s = {{src, -1}};
    while (!s.empty()) {
        int x = s.back().first, y, e, &it = its[x], end = sz(gr[x]);
        int p_e = s.back().second;
        if (it == end) {
            ret.push_back(p_e);
            s.pop_back();
            continue;
        }
        tie(y, e) = gr[x][it++];
        if (!eu[e]) {
            D[x]--, D[y]++;
            eu[e] = 1;
            s.push_back({y, e});
        }
    }
    for (int x : D)
        if (x < 0 || sz(ret) != nedges + 1) return {};
    return {ret.rbegin(), ret.rend()};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (auto& [x, y] : a) cin >> x >> y, --x, --y;

    for (int b = 20; b >= 0; --b) {
        const int mask = (1 << b) - 1;

        vector<vector<pair<int, int>>> g(1 << b);
        {
            int idx = 0;
            for (auto [u, v] : a) {
                g[u & mask].emplace_back(v & mask, idx);
                g[v & mask].emplace_back(u & mask, idx);
                ++idx;
            }
        }

        if ([&]() {
                rep(u, 0, 1 << b) if (sz(g[u]) % 2 == 1) return true;
                return false;
            }())
            continue;

        const int root = a[0][0] & mask;

        int edges = 0;
        vector<bool> vis(1 << b);
        auto dfs = [&](const auto& self, int u) -> void {
            vis[u] = true;
            for (auto [v, i] : g[u]) {
                ++edges;
                if (!vis[v]) self(self, v);
            }
        };
        dfs(dfs, root);
        if (edges != 2 * n) continue;

        auto res = eulerWalk(g, n, root);
        assert(res[0] == -1);

        res.erase(begin(res));
        assert(sz(res) == n);

        vector<int> ans = {2 * res[0], 2 * res[0] + 1};

        int p = a[res[0]][1];
        rep(i, 1, n) {
            if ((p & mask) == (a[res[i]][0] & mask)) {
                ans.push_back(2 * res[i]);
                ans.push_back(2 * res[i] + 1);
                p = a[res[i]][1];
            } else {
                assert((p & mask) == (a[res[i]][1] & mask));
                ans.push_back(2 * res[i] + 1);
                ans.push_back(2 * res[i]);
                p = a[res[i]][0];
            }
        }

        rep(i, 0, n) {
            const int x = ans[2 * i + 1];
            const int y = ans[(2 * i + 2) % (2 * n)];
            assert(((a[x >> 1][x & 1] ^ a[y >> 1][y & 1]) & mask) == 0);
        }

        cout << b << '\n';
        for (auto x : ans) cout << x + 1 << ' ';
        cout << '\n';
        break;
    }
}
