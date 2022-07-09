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

    vector<int> in(n, -1), out(n, -1);
    {
        int timer = 0;
        auto init = [&](const auto& self, int u) -> void {
            in[u] = timer++;
            for (auto v : g[u])
                if (in[v] < 0) self(self, v);
            out[u] = timer;
        };
        init(init, 0);
        assert(in[0] == 0 && out[0] == n);
    }
    vector<int> inv(n);
    rep(u, 0, n) inv[in[u]] = u;

    struct event {
        int l, r, k, idx;
    };

    vector<event> ev(q);
    {
        int i = 0;
        for (auto& [l, r, k, idx] : ev) {
            int v;
            cin >> v >> k;
            --v;
            l = in[v];
            r = out[v] - 1;
            idx = i++;
        }
    }

    constexpr int B = 400;
    sort(all(ev),
         [&](const event& a, const event& b) { return pair(a.l / B, a.r) < pair(b.l / B, b.r); });

    const int distinct = *max_element(all(c)) + 1;
    vector<int> f(distinct), cnt(n + 1);
    cnt[0] = distinct;

    int cur_l = 0, cur_r = -1;
    auto add = [&](int x) -> void { ++cnt[++f[c[inv[x]]]]; };
    auto remove = [&](int x) -> void { --cnt[f[c[inv[x]]]--]; };

    vector<int> ans(q);

    for (auto [l, r, k, idx] : ev) {
        // [l, r]
        while (cur_l > l) add(--cur_l);
        while (cur_r < r) add(++cur_r);

        while (cur_l < l) remove(cur_l++);
        while (cur_r > r) remove(cur_r--);

        ans[idx] = k > n ? 0 : cnt[k];
    }

    for (auto x : ans) cout << x << '\n';
}
