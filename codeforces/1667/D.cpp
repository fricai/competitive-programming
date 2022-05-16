#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a);)
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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(e, 1, n) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> parity(n);
    auto poss = [&](const auto& dfs, int u, int p) -> bool {
        int cnt[2] = {};
        for (auto v : g[u]) {
            if (v == p) continue;
            if (!dfs(dfs, v, u)) return false;
            ++cnt[parity[v]];
        }
        if (u != p) {
            parity[u] = cnt[0] >= cnt[1];
            ++cnt[parity[u]];
        }
        const auto del = cnt[1] - cnt[0];
        return 0 <= del && del <= 1;
    };
    if (!poss(poss, 0, 0)) return void(cout << "NO\n");

    auto cons = [&](const auto& dfs, int u, int p) -> void {
        vector<int> part[2];
        for (auto v : g[u]) {
            if (v != p)
                part[parity[v]].push_back(v);
            else
                part[parity[u]].push_back(p);
        }
        per(i, 0, sz(g[u])) {
            auto v = part[~i & 1].back();
            if (v != p)
                dfs(dfs, v, u);
            else
                cout << u + 1 << ' ' << v + 1 << '\n';
            part[~i & 1].pop_back();
        }
    };
    cout << "YES\n";
    cons(cons, 0, 0);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
