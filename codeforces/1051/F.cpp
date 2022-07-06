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


#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder


struct tree {
    int n;
    vector<vector<pair<int, int>>> g;
    vector<ll> d;
    vector<int> dep;
    int root;
    static constexpr int B = 18;
    array<vector<int>, B> p;

    tree(int n) : n{n}, g(n), d(n, -1), dep(n), root{0} { fill(all(p), vector<int>(n, -1)); }

    void add_edge(int u, int v, int d) {
        g[u].emplace_back(v, d);
        g[v].emplace_back(u, d);
    }

    void init_dfs(int u) {
        for (auto [v, w] : g[u]) {
            if (d[v] < 0) {
                p[0][v] = u;
                d[v] = d[u] + w;
                dep[v] = dep[u] + 1;
                init_dfs(v);
            }
        }
    }

    void init() {
        d[root] = 0;
        dep[root] = 0;
        p[0][root] = root;
        init_dfs(root);
        rep(j, 0, B - 1) rep(u, 0, n) p[j + 1][u] = p[j][p[j][u]];
    }

    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        const int diff = dep[u] - dep[v];
        rep(j, 0, B) if (diff >> j & 1) u = p[j][u];
        if (u == v) return u;
        per(j, 0, B) if (p[j][u] != p[j][v]) u = p[j][u], v = p[j][v];
        return p[0][u];
    }

    auto dist(int u, int v) { return d[u] + d[v] - 2 * d[lca(u, v)]; }
};

template <class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
auto dijkstra(int s, const vector<vector<pair<int, int>>>& g) {
    constexpr ll inf = 1e18;
    const int n = g.size();
    vector<ll> d(n, inf);
    d[s] = 0;
    minpq<pair<ll, int>> q;
    q.push({0, s});
    while (!q.empty()) {
        auto [d_u, u] = q.top();
        q.pop();
        if (d_u != d[u]) continue;
        for (auto [v, w] : g[u]) {
            if (uin(d[v], d[u] + w)) {
                q.push({d[v], v});
            }
        }
    }
    assert(all_of(all(d), [](auto x) { return x < inf; }));
    return d;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    atcoder::dsu D(n);
    tree t(n);

    vector<vector<pair<int, int>>> g(n);

    vector<int> ex;
    rep(e, 0, m) {
        int u, v, d;
        cin >> u >> v >> d;
        --u, --v;

        g[u].emplace_back(v, d);
        g[v].emplace_back(u, d);
        if (D.same(u, v)) {
            ex.push_back(u);
        } else {
            t.add_edge(u, v, d);
            D.merge(u, v);
        }
    }
    t.init();

    sort(all(ex));
    ex.erase(unique(all(ex)), end(ex));

    vector<vector<ll>> dis(sz(ex));
    per(i, 0, sz(ex)) dis[i] = dijkstra(ex[i], g);

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;

        auto ans = t.dist(x, y);
        static_assert(is_same<decltype(ans), ll>::value);
        for (auto& v : dis) uin(ans, v[x] + v[y]);
        cout << ans << '\n';
    }
}
