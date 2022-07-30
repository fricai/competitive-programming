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
using minpq = priority_queue<T, vector<T>, greater<T>>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, start;
    cin >> n >> m >> start;
    --start;

    vector<vector<pair<int, int>>> in(n);
    // vector<vector<pair<int, int>>> out(n);
    vector<int> outdeg(n);

    rep(e, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;

        in[v].emplace_back(u, w);

        // out[u].emplace_back(v, w);
        ++outdeg[u];
    }

    vector<array<bool, 2>> finite(n);
    vector<array<ll, 2>> dp(n);

    minpq<tuple<ll, int, bool>> pq;

    rep(u, 0, n) {
        if (outdeg[u] != 0) continue;
        // finite[u][0] = finite[u][1] = true;
        pq.push({0, u, 0});
        pq.push({0, u, 1});
    }

    while (!pq.empty()) {
        auto [val, u, p] = pq.top();
        pq.pop();
        if (finite[u][p]) continue;
        finite[u][p] = true;
        dp[u][p] = val;

        if (p == 0) {
            for (auto [v, w] : in[u]) {
                uax(dp[v][1], dp[u][0] + w);
                if (--outdeg[v] == 0) {
                    pq.push({dp[v][1], v, 1});
                }
            }
        } else {
            for (auto [v, w] : in[u]) pq.push({dp[u][1] + w, v, 0});
        }
    }

    if (finite[start][0])
        cout << dp[start][0] << '\n';
    else
        cout << "INFINITY\n";
}
