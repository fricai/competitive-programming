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

template <class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j, 0, sz(jmp[k])) jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b);  // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct LCA {
    int T = 0;
    vector<int> time, path, ret;
    RMQ<int> rmq;

    LCA(vector<vector<int>>& C) : time(sz(C)), rmq((dfs(C, 0, -1), ret)) {}

    void dfs(vector<vector<int>>& C, int v, int par) {
        time[v] = T++;
        for (int y : C[v])
            if (y != par) {
                path.push_back(v), ret.push_back(time[v]);
                dfs(C, y, v);
            }
    }

    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
    // dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

auto compressTree(LCA& lca, const vector<int>& subset) {
    static vector<int> rev;
    rev.resize(sz(lca.time));
    vector<int> li = subset, &T = lca.time;
    auto cmp = [&](int a, int b) { return T[a] < T[b]; };
    sort(all(li), cmp);
    int m = sz(li) - 1;
    rep(i, 0, m) {
        int a = li[i], b = li[i + 1];
        li.push_back(lca.lca(a, b));
    }
    sort(all(li), cmp);
    li.erase(unique(all(li)), li.end());
    rep(i, 0, sz(li)) rev[li[i]] = i;
    vector<pair<int, int>> ret;
    rep(i, 0, sz(li) - 1) {
        int a = li[i], b = li[i + 1];
        ret.emplace_back(rev[lca.lca(a, b)], b);
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    rep(e, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto lca = LCA(g);

    int q;
    cin >> q;
    rep(i, 0, q) {
        int k;
        cin >> k;
        vector<int> vec(k);
        for (auto& x : vec) cin >> x, --x;

        if (k == 1) {
            cout << "YES\n";
        } else {
            auto res = compressTree(lca, vec);

            const int r = sz(res);
            vector<int> deg(r + 1);
            rep(i, 0, r) {
                ++deg[i + 1];
                ++deg[res[i].first];
            }

            const int leaves = count(all(deg), 1);
            assert(leaves >= 2);
            cout << (leaves == 2 ? "YES" : "NO") << '\n';
        }
    }
}
