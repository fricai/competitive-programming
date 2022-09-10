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
    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    vector<vector<int>> g(n);
    rep(e, 0, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto check = [&](ll x) -> bool {
        vector<ll> cost(n);
        rep(u, 0, n) for (auto v : g[u]) cost[u] += a[v];

        vector<uint8_t> vis(n, false);

        queue<int> q;
        rep(u, 0, n) if (cost[u] <= x) {
            q.push(u);
            vis[u] = true;
        }

        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto v : g[u]) {
                if (vis[v]) continue;
                cost[v] -= a[u];
                if (cost[v] <= x) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }

        return accumulate(all(vis), 0) == n;
    };

    constexpr ll inf = 1e16;
    ll l = -1, r = inf;
    while (r - l > 1) {
        const auto m = (l + r) / 2;
        (check(m) ? r : l) = m;
    }
    cout << r << '\n';
}
