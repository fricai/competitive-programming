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

    vector<int> deg(n);
    vector<vector<int>> g(n);
    rep(e, 0, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++deg[u], ++deg[v];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (auto x : deg)
        if (x % 2 != 0) return cout << "No\n", 0;

    for (auto x : deg)
        if (x >= 6) return cout << "Yes\n", 0;

    for (auto x : deg) assert(x == 2 || x == 4);

    vector<int> cand;
    rep(u, 0, n) if (deg[u] == 4) cand.push_back(u);
    if (sz(cand) > 2) return cout << "Yes\n", 0;
    if (sz(cand) < 2) return cout << "No\n", 0;

    // There should exist precisely two paths between them
    const int a = cand[0], b = cand[1];
    auto dfs = [&](const auto& self, int u, int p) -> bool {
        if (u == a) return false;
        if (u == b) return true;
        assert(sz(g[u]) == 2);
        return self(self, g[u][0] ^ g[u][1] ^ p, u);
    };

    int paths = 0;
    for (auto v : g[a]) paths += dfs(dfs, v, a);

    cout << (paths == 2 ? "Yes\n" : "No\n");
}
