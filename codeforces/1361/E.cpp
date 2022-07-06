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

void solve() {
    constexpr int tries = 80;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    rep(e, 0, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
    }

    int root = -1;

    {
        uniform_int_distribution<> dis(0, n - 1);
        rep(i, 0, tries) {
            root = dis(rng);

            bool is_interesting = true;

            vector<int> in_time(n), out_time(n);
            int cntr = 0;
            auto dfs = [&](const auto& self, int u) -> void {
                in_time[u] = ++cntr;
                for (auto v : g[u]) {
                    if (in_time[v] == 0) {
                        self(self, v);
                    } else {
                        if (in_time[v] <= in_time[u] && out_time[v] == 0) {
                            // this is an ancestor
                        } else {
                            is_interesting = false;
                        }
                    }
                }
                out_time[u] = cntr;
            };
            dfs(dfs, root);

            // every edge has to be a tree or back edge
            if (is_interesting)
                break;
            else
                root = -1;
        }
    }
    if (root == -1) return cout << "-1\n", void();

    vector<bool> is_interesting(n);
    is_interesting[root] = true;

    vector<int> cnt(n), hsh(n);

    vector<int> in_time(n), out_time(n);
    int cntr = 0;
    auto dfs = [&](const auto& self, int u) -> void {
        in_time[u] = ++cntr;

        for (auto v : g[u]) {
            if (in_time[v] == 0) {
                self(self, v);
                hsh[u] ^= hsh[v];
                cnt[u] += cnt[v];
            } else {
                assert(in_time[v] <= in_time[u] && out_time[v] == 0);
                // v is an ancestor of u
                hsh[u] ^= v;
                hsh[v] ^= v;
                ++cnt[u];
                --cnt[v];
            }
        }

        out_time[u] = cntr;
    };
    dfs(dfs, root);

    in_time.assign(n, 0);
    cntr = 0;
    auto pull = [&](const auto& self, int u) -> void {
        if (cnt[u] == 1) is_interesting[u] = is_interesting[hsh[u]];

        in_time[u] = ++cntr;
        for (auto v : g[u])
            if (in_time[v] == 0) self(self, v);
    };
    pull(pull, root);

    const int k = count(all(is_interesting), true);
    if (5 * k < n) return cout << "-1\n", void();
    rep(u, 0, n) if (is_interesting[u]) cout << u + 1 << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
