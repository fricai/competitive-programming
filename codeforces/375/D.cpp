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

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

namespace hashing {
using ull = std::uint64_t;
static const ull FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();

template <class T, class D = void>
struct custom_hash {};

// https://www.boost.org/doc/libs/1_55_0/doc/html/hash/combine.html
template <class T>
inline void hash_combine(ull& seed, const T& v) {
    custom_hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b97f4a7c15 + (seed << 12) + (seed >> 4);
};

// http://xorshift.di.unimi.it/splitmix64.c
template <class T>
struct custom_hash<T, typename std::enable_if<std::is_integral<T>::value>::type> {
    ull operator()(T v) const {
        ull x = v + 0x9e3779b97f4a7c15 + FIXED_RANDOM;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
};

template <class T>
struct custom_hash<T, std::void_t<decltype(std::begin(std::declval<T>()))>> {
    ull operator()(const T& a) const {
        ull value = FIXED_RANDOM;
        for (auto& x : a) hash_combine(value, x);
        return value;
    }
};

template <class... T>
struct custom_hash<std::tuple<T...>> {
    ull operator()(const std::tuple<T...>& a) const {
        ull value = FIXED_RANDOM;
        std::apply([&value](T const&... args) { (hash_combine(value, args), ...); }, a);
        return value;
    }
};

template <class T, class U>
struct custom_hash<std::pair<T, U>> {
    ull operator()(const std::pair<T, U>& a) const {
        ull value = FIXED_RANDOM;
        hash_combine(value, a.first);
        hash_combine(value, a.second);
        return value;
    }
};

};  // namespace hashing

template <class T>
struct SparseFenwick2D {
    int n, m;
    __gnu_pbds::gp_hash_table<int, __gnu_pbds::gp_hash_table<int, T, hashing::custom_hash<int>>,
                              hashing::custom_hash<int>>
        t;
    SparseFenwick2D(int n, int m) : n(n), m(m) {}
    T query(int i, int j) {
        T s{};
        for (int x = i; x > 0; x -= x & (-x)) {
            auto it = t.find(x);
            if (it == t.end()) continue;
            auto& tx = it->second;
            for (int y = j; y > 0; y -= y & (-y)) s += tx[y];
        }
        return s;
    }
    T query(int i1, int j1, int i2, int j2) {
        assert(i2 == n);
        // [1, m] -> [m, 1]
        // j2 -> m - j2 + 1
        i2 = n - i1 + 1;
        return query(i2, j2) - query(i2, j1 - 1);
    }
    void update(int i, int j, T v) {
        i = m - i + 1;
        for (int x = i; x <= n; x += x & (-x)) {
            auto& tx = t[x];
            for (int y = j; y <= m; y += y & (-y)) tx[y] += v;
        }
    }
};

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

    const int col_cnt = *max_element(all(c)) + 1;

    constexpr int B = 17;
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
    }
    {
        vector<int> tmp(n);
        rep(i, 0, n) tmp[in[i]] = c[i];
        c = move(tmp);
    }

    SparseFenwick2D<int> t(n, n);

    {
        auto is_ancestor = [&nxt](int i, int j) -> bool { return i <= j && j < nxt[i]; };

        auto lca = [&](int u, int v) -> int {
            if (is_ancestor(u, v)) return u;
            if (is_ancestor(v, u)) return v;
            per(j, 0, B) if (!is_ancestor(p[j][u], v)) u = p[j][u];
            return p[0][u];
        };

        vector<vector<int>> occ(col_cnt);
        rep(i, 0, n) occ[c[i]].push_back(i);

        rep(col, 0, col_cnt) {
            auto& vec = occ[col];

            const int m = sz(vec);

            sort(all(vec));

            auto full = vec;
            full.reserve(2 * m - 1);
            rep(i, 0, m - 1) full.push_back(lca(vec[i], vec[i + 1]));

            sort(all(full));
            full.erase(unique(all(full)), end(full));

            int prev_u = -1;
            for (auto u : full) {
                const int cnt = int(lower_bound(all(vec), nxt[u]) - lower_bound(all(vec), u));
                // number of elements in vec in subtree of u
                // (elements in vec < nxt[u]) - (elements in vec < u)

                // increment all ancestors of u (including itself)
                t.update(cnt, u + 1, +1);
                if (prev_u != -1) t.update(cnt, lca(u, prev_u) + 1, -1);
                prev_u = u;
            }
        }
        // pref[j][i] = number of colours which occur j times in the subtree of j

        // now sum(pref[j][i...nxt[i])) gives us number of colours which occurred j times
        // so sum(pref[j...n)[i...nxt[i])) gives us number of occurred >= j times
    }

    rep(i, 0, q) {
        int v, k;
        cin >> v >> k;
        v = in[v - 1];

        if (k > n)
            cout << "0\n";
        else
            cout << t.query(k, v + 1, n, nxt[v]) << '\n';
    }
}
