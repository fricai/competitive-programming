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

    vector<vector<int>> g(n);
    rep(e, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> in(n, -1), siz(n, -1);
    {
        int timer = 0;
        auto init = [&](const auto& self, int u) -> void {
            in[u] = timer++;
            for (auto v : g[u])
                if (in[v] < 0) self(self, v);
            siz[u] = timer - in[u];
        };
        init(init, 0);
        assert(in[0] == 0 && siz[0] == n);
    }
    vector<int> inv(n);
    rep(u, 0, n) inv[in[u]] = u;
    {
        vector<int> tmp(n);
        rep(i, 0, n) tmp[in[i]] = c[i];
        c = move(tmp);
    }

    vector<vector<pair<int, int>>> ev(n);

    rep(i, 0, q) {
        int v, k;
        cin >> v >> k;
        --v;
        ev[v].emplace_back(k, i);
    }
    for (auto& vec : ev) vec.shrink_to_fit();

    vector<int> ans(q);
    vector<map<int, int>> f(n), cnt(n);

    per(i, 0, n) {
        const int u = inv[i];

        int heaviest = -1;
        for (auto v : g[u])
            if (in[u] <= in[v] && (heaviest == -1 || siz[heaviest] < siz[v])) heaviest = v;

        auto add = [&](int col) { ++cnt[u][++f[u][col]]; };

        if (heaviest != -1) {
            f[u] = move(f[heaviest]);
            cnt[u] = move(cnt[heaviest]);

            rep(j, in[u], in[heaviest]) add(c[j]);
            const int lst = in[u] + siz[u];
            rep(j, in[heaviest] + siz[heaviest], lst) add(c[j]);
        } else {
            add(c[i]);
        }

        for (auto [k, idx] : ev[u])
            if (auto it = cnt[u].find(k); it != cnt[u].end())
                ans[idx] = it->second;
            else
                ans[idx] = 0;
    }

    for (auto x : ans) cout << x << '\n';
}
