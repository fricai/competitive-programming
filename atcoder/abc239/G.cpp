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

#include <atcoder/maxflow>

constexpr ll inf = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    atcoder::mf_graph<ll> g(2 * n);
    rep(e, 0, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g.add_edge(u << 1 | 1, v << 1 | 0, inf);
        g.add_edge(v << 1 | 1, u << 1 | 0, inf);
    }

    vector<int> c(n);
    for (auto& x : c) cin >> x;

    rep(u, 1, n - 1) g.add_edge(u << 1 | 0, u << 1 | 1, c[u]);

    const auto flow = g.flow(1, (n - 1) << 1);
    const auto status = g.min_cut(1);

    vector<int> ans;
    rep(u, 1, n - 1) if (status[u << 1 | 0] && !status[u << 1 | 1]) ans.push_back(u);

    cout << flow << '\n' << sz(ans) << '\n';
    for (auto u : ans) cout << u + 1 << ' ';
    cout << '\n';
}
