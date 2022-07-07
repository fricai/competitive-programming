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

constexpr int A = 26;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<pair<int, char>>> g(n);
    rep(e, 0, n - 1) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        --u, --v;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    vector<int> dep(n);
    vector<array<int, A>> t(n);
    auto init_dfs = [&](const auto& self, int u, int p) -> void {
        fill(all(t[u]), -1);
        for (auto [v, c] : g[u])
            if (v != p) {
                t[u][c - 'a'] = v;
                dep[v] = dep[u] + 1;
                self(self, v, u);
            }
    };
    init_dfs(init_dfs, 0, -1);

    auto parallel_dfs = [&](const auto& self, const vector<int>& nodes) -> int {
        if (sz(nodes) <= 1) return 0;

        int res = sz(nodes) - 1;
        vector<int> nxt;
        rep(c, 0, A) {
            nxt.clear();
            for (auto u : nodes)
                if (t[u][c] != -1) nxt.push_back(t[u][c]);
            res += self(self, nxt);
        }
        return res;
    };

    vector<int> ans(n);
    {
        vector<int> nxt;
        rep(u, 0, n) {
            nxt.clear();
            for (auto v : t[u])
                if (v != -1) nxt.push_back(v);
            ans[dep[u]] += parallel_dfs(parallel_dfs, nxt) + (nxt.empty() ? 0 : 1);
        }
    }

    const int p = max_element(all(ans)) - begin(ans);
    cout << n - ans[p] << '\n' << p + 1 << '\n';
}
