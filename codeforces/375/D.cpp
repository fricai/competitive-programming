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

template <class T, T id = T{}>
struct point_update_range_query {
    int n;
    vector<int> t;

    static constexpr int pow_ceil(int n) {
        int sz = 1;
        while (sz < n) sz <<= 1;
        return sz;
    }

    explicit point_update_range_query(int _n) : n{pow_ceil(_n)}, t(n << 1, id) {}

    T query(int l, int r) const {
        T res{id};
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }
        return res;
    }

    void update(int p, T val) {
        for (t[p += n] += val; p >>= 1;) t[p] = t[p << 1] + t[p << 1 | 1];
    }
};

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

    vector<vector<int>> pos(n + 1), neg(n + 1);
    {
        auto is_ancestor = [&nxt](int i, int j) -> bool { return i <= j && j < nxt[i]; };

        auto lca = [&](int u, int v) -> int {
            if (is_ancestor(u, v)) return u;
            if (is_ancestor(v, u)) return v;
            per(j, 0, B) if (!is_ancestor(p[j][u], v)) u = p[j][u];
            return p[0][u];
        };

        vector<vector<int>> occ(col_cnt);
        rep(i, 0, n) occ[c[i]].push_back(i);

        rep(col, 0, col_cnt) {
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
                // number of elements in vec in subtree of u
                // (elements in vec < nxt[u]) - (elements in vec < u)

                // increment all ancestors of u (including itself)
                assert(cnt <= n);
                pos[cnt].push_back(u);
                if (prev_u != -1) neg[cnt].push_back(lca(u, prev_u));
                prev_u = u;
            }
        }
        // pref[j][i] = number of colours which occur j times in the subtree of j

        // now sum(pref[j][i...nxt[i])) gives us number of colours which occurred j times
        // so sum(pref[j...n)[i...nxt[i])) gives us number of occurred >= j times
    }

    vector<int> ans(q);
    vector<vector<pair<int, int>>> ev(n + 1);

    rep(i, 0, q) {
        int v, k;
        cin >> v >> k;
        v = in[v - 1];
        if (k <= n) ev[k].emplace_back(v, i);
    }

    point_update_range_query<int, 0> tr(n);
    for (int k = n; k > 0; --k) {
        for (auto x : pos[k]) tr.update(x, +1);
        for (auto x : neg[k]) tr.update(x, -1);
        for (auto [v, i] : ev[k]) ans[i] = tr.query(v, nxt[v]);
    }

    for (auto x : ans) cout << x << '\n';
}
