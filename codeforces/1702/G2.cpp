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

    int n;
    cin >> n;

    constexpr int B = 18;
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

        // can forget in now
    }

    auto is_ancestor = [&](int i, int j) -> bool { return i <= j && j < nxt[i]; };

    auto lca = [&](int u, int v) -> int {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        per(j, 0, B) if (!is_ancestor(p[j][u], v)) u = p[j][u];
        assert(is_ancestor(p[0][u], v));
        return p[0][u];
    };

    vector<int> rev(n);

    int q;
    cin >> q;
    rep(i, 0, q) {
        int k;
        cin >> k;
        vector<int> vec(k);
        for (auto& x : vec) cin >> x, x = in[x - 1];

        if (k == 1) {
            cout << "YES\n";
        } else {
            sort(all(vec));

            auto full = vec;
            full.reserve(2 * k - 1);
            rep(i, 1, k) full.push_back(lca(vec[i - 1], vec[i]));

            sort(all(full));
            full.erase(unique(all(full)), end(full));
            const int r = sz(full);
            rep(i, 0, r) rev[full[i]] = i;

            vector<int> deg(r, 0);
            rep(i, 1, r) deg[rev[lca(full[i - 1], full[i])]]++;
            --deg[0];

            int leaves = count(all(deg), 0);

            assert(leaves >= 2);
            cout << (leaves <= 2 ? "YES" : "NO") << '\n';
        }
    }
}
