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

    int n, q;
    cin >> n >> q;

    vector<int> c(n);
    for (auto& x : c) cin >> x, --x;
    {
        auto cmp = c;
        sort(all(cmp));
        cmp.erase(unique(all(cmp)), end(cmp));
        for (auto& x : c) x = int(lower_bound(all(cmp), x) - begin(cmp));
    }

    const int col_cnt = *max_element(all(c)) + 1;

    constexpr int MAG = 300;

    vector<int> heavy;
    vector<bool> light(col_cnt);
    {
        vector<int> tot_freq(col_cnt);
        for (auto x : c) ++tot_freq[x];
        rep(i, 0, col_cnt) {
            assert(tot_freq[i] != 0);
            if (tot_freq[i] < MAG)
                light[i] = true;
            else
                heavy.push_back(i);
        }
        heavy.shrink_to_fit();
    }

    constexpr int B = 17;
    array<vector<int>, B> p;
    vector<int> nxt(n, -1), in(n, -1);

    {
        vector<vector<int>> g(n);
        rep(e, 0, n - 1) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        {
            int timer = 0;
            auto init = [&](const auto& self, int u) -> void {
                in[u] = timer++;
                for (auto v : g[u])
                    if (in[v] < 0) {
                        self(self, v);
                        p[0][in[v]] = in[u];
                    }
                nxt[in[u]] = timer;
            };
            p[0].resize(n);
            init(init, 0);
            assert(in[0] == 0 && nxt[0] == n);

            rep(j, 0, B - 1) {
                p[j + 1].resize(n);
                rep(u, 0, n) p[j + 1][u] = p[j][p[j][u]];
            }
        }
        // can forget g now
    }
    {
        vector<int> tmp(n);
        rep(i, 0, n) tmp[in[i]] = c[i];
        c = move(tmp);
    }

    vector<vector<pair<int, int>>> ev(n);

    rep(i, 0, q) {
        int v, k;
        cin >> v >> k;
        v = in[v - 1];
        ev[v].emplace_back(k, i);
    }
    for (auto& vec : ev) vec.shrink_to_fit();

    vector<int> ans(q);

    {
        // light colours

        auto is_ancestor = [&](int i, int j) -> bool { return i <= j && j < nxt[i]; };

        auto lca = [&](int u, int v) -> int {
            if (is_ancestor(u, v)) return u;
            if (is_ancestor(v, u)) return v;
            per(j, 0, B) if (!is_ancestor(p[j][u], v)) u = p[j][u];
            assert(is_ancestor(p[0][u], v));
            return p[0][u];
        };

        vector<vector<int>> occ(col_cnt);
        rep(i, 0, n) if (light[c[i]]) occ[c[i]].push_back(i);

        array<vector<int>, MAG> pref;
        for (auto& v : pref) v.resize(n + 1);

        rep(col, 0, col_cnt) {
            if (!light[col]) continue;

            auto& vec = occ[col];
            const int m = sz(vec);

            sort(all(vec));

            auto full = vec;
            full.reserve(2 * m - 1);
            rep(i, 0, m - 1) full.push_back(lca(vec[i], vec[i + 1]));

            sort(all(full));
            full.erase(unique(all(full)), end(full));

            int prev_u = -1;
            for (auto u : full) {
                const int cnt = int(lower_bound(all(vec), nxt[u]) - lower_bound(all(vec), u));
                assert(cnt < MAG);
                // number of elements in vec in subtree of u
                // (elements in vec < nxt[u]) - (elements in vec < u)

                // increment all ancestors of u (including itself)
                ++pref[cnt][u + 1];
                if (prev_u != -1)
                    --pref[cnt][lca(u, prev_u) + 1];
                else
                    --pref[cnt][0];
                prev_u = u;
            }
        }
        // pref[j][i] = number of colours which occur j times in the subtree of j

        // now sum(pref[j][i...nxt[i])) gives us number of colours which occurred j times
        // so sum(pref[j...n)[i...nxt[i])) gives us number of occurred >= j times
        per(i, 1, MAG) rep(u, 0, n + 1) pref[i - 1][u] += pref[i][u];
        rep(i, 0, MAG) rep(u, 0, n) pref[i][u + 1] += pref[i][u];
        rep(i, 0, n) {
            for (auto [k, idx] : ev[i]) ans[idx] = k < MAG ? pref[k][nxt[i]] - pref[k][i] : 0;
        }
    }

    {
        // heavy colours
        const int m = heavy.size();
        vector pref(m, vector(n + 1, 0));
        rep(i, 0, m) rep(j, 0, n) pref[i][j + 1] += pref[i][j] + (c[j] == heavy[i]);

        per(i, 0, n) {
            for (const auto& v : pref) {
                const int del = v[nxt[i]] - v[i];
                for (auto [k, idx] : ev[i]) ans[idx] += del >= k;
            }
        }
    }

    for (auto x : ans) cout << x << '\n';
}
