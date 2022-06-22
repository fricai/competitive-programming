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

using point = complex<ll>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(e, 1, n) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (auto& v : g)
        if (sz(v) > 4) return cout << "NO\n", 0;

    vector<point> pts(n);
    constexpr array<point, 4> del{{{+1, 0}, {0, +1}, {-1, 0}, {0, -1}}};
    ll len = 1 << 30;
    auto dfs = [&](const auto& rec, int u, int p, int p_dir) -> void {
        int i = 0;
        for (auto v : g[u]) {
            if (v == p) continue;
            if (i == p_dir) ++i;
            pts[v] = len * del[i] + pts[u];
            len /= 2;
            rec(rec, v, u, (i + 2) % 4);
            ++i;
        }
    };
    const int root = 0;
    pts[root] = 0;
    dfs(dfs, root, root, -1);

    cout << "YES\n";
    for (auto p : pts) cout << real(p) << ' ' << imag(p) << '\n';
}
