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

    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (auto& v : p) cin >> v, --v;

    int ans = p[0] == 0 ? 0 : 1;
    p[0] = 0;

    vector<int> h(n);
    vector<vector<int>> g(n);
    rep(i, 1, n) g[p[i]].push_back(i);
    auto dfs = [&](const auto& self, int u) -> void {
        for (auto v : g[u]) {
            self(self, v);
            if ((u != 0 && h[v] == k - 1) || (u == 0 && h[v] == k)) {
                ++ans;
            } else {
                h[u] = max(h[u], 1 + h[v]);
            }
        }
    };
    dfs(dfs, 0);
    cout << ans << '\n';
}
