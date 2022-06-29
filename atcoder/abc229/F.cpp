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

constexpr int inf = 1e9 + 10;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 0 -> N
    // [1, N] -> [0, N)

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    vector<array<array<ll, 2>, 2>> dp(n);
    // 0 -> white, 1 -> block
    // node N is white
    //
    // dp[n][b][c] = color of node n is c, color of node 0 is b

    dp[0][0][0] = a[0];
    dp[0][1][0] = inf;
    dp[0][0][1] = inf;
    dp[0][1][1] = 0;
    rep(i, 0, n - 1) {
        for (auto c : {0, 1}) {
            dp[i + 1][c][0] = a[i + 1] + min(dp[i][c][1], b[i] + dp[i][c][0]);
            dp[i + 1][c][1] = min(dp[i][c][0], b[i] + dp[i][c][1]);
        }
    }

    cout << min({b[n - 1] + min(dp[n - 1][0][0], dp[n - 1][1][1]), dp[n - 1][0][1],
                 dp[n - 1][1][0]})
         << '\n';
}
