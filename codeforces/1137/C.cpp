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

/*
auto FindSCC(const vector<vector<int>>& G, int const Base) {
    vector<vector<int>> SCC;
    vector<unsigned> S, P, depth(G.size());
    const auto dfs = [&](const auto& self, auto u) -> void {
        auto d = S.size();
        S.push_back(u);
        P.push_back(d + 1);
        depth[u] = d + 1;
        for (auto v : G[u]) {
            if (!depth[v])
                self(self, v);
            else
                while (P.back() > depth[v]) P.pop_back();
        }
        if (P.back() > d) {
            SCC.emplace_back(S.begin() + d, S.end());
            for (auto v : SCC.back()) depth[v] = -1;
            S.erase(S.begin() + d, S.end());
            P.pop_back();
        }
    };
    for (auto u = Base; u < G.size(); ++u)
        if (!depth[u]) dfs(dfs, u);
    // reverse(SCC.begin(), SCC.end());
    return SCC;
}
*/

// https://github.com/cheran-senthil/PyRival/blob/7f55058bd657f52c8eda69a7332fb3db30bbaa86/pyrival/graphs/scc.py
auto FindSCC(const vector<vector<int>>& G) {
    const int n = G.size();

    vector<vector<int>> SCC;
    vector<int> S, P, depth(n, 0);
    vector<unsigned> st(n);
    iota(all(st), 0);

    while (!st.empty()) {
        auto v = st.back();
        st.pop_back();
        if (v >= G.size()) {
            auto d = depth[~v] - 1;
            if (P.back() > d) {
                SCC.emplace_back(S.begin() + d, S.end());
                P.pop_back();
                S.erase(S.begin() + d, S.end());
                for (auto u : SCC.back()) depth[u] = -1;
            }
        } else if (depth[v] > 0) {
            while (P.back() > depth[v]) {
                P.pop_back();
            }
        } else if (depth[v] == 0) {
            S.push_back(v);
            P.push_back(sz(S));
            depth[v] = sz(S);
            st.push_back(~v);
            st.insert(st.end(), all(G[v]));
        }
    }
    return SCC;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, d;
    cin >> n >> m >> d;

    auto hsh = [&](int u, int i) -> int { return u * d + i; };

    vector<vector<int>> g(n * d);
    rep(e, 0, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        rep(i, 0, d) g[hsh(u, i)].push_back(hsh(v, (i + 1) % d));
    }
    for (auto& v : g) v.shrink_to_fit();

    vector av(n, vector<bool>(d));
    rep(u, 0, n) {
        string s;
        cin >> s;
        assert(sz(s) == d);
        rep(i, 0, d) av[u][i] = s[i] == '1';
    }

    // if path from (v, i) -> (v, j) then path from (v, j) -> (v, i)
    // so no two vertices will lie in on the same path in kernel graph

    auto scc = FindSCC(g);

    const int r = sz(scc);

    vector<int> cmp(n * d);
    rep(i, 0, r) for (auto u : scc[i]) cmp[u] = i;

    const int mx = cmp[0] + 1;

    vector<int> cnt(mx);
    {
        vector<int> v;
        rep(i, 0, mx) {
            for (auto x : scc[i])
                if (av[x / d][x % d]) v.push_back(x / d);
            sort(all(v));
            cnt[i] = unique(all(v)) - begin(v);
            v.clear();
        }
    }

    vector<int> res(mx);
    rep(i, 0, mx) {
        for (auto u : scc[i]) {
            for (auto v : g[u]) {
                if (cmp[v] == i) continue;
                assert(cmp[v] < i);
                res[i] = max(res[i], res[cmp[v]]);
            }
        }
        res[i] += cnt[i];
    }

    cout << res[cmp[0]] << '\n';
}
