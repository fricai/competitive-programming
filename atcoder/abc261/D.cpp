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

    int n, m;
    cin >> n >> m;

    vector<ll> x(n);
    for (auto& a : x) cin >> a;

    vector<ll> bonus(n + 1);
    rep(i, 0, m) {
        int c, y;
        cin >> c >> y;
        bonus[c] = y;
    }

    vector<ll> dp(n + 1);
    dp[0] = 0;

    rep(i, 0, n) {
        dp[i + 1] = dp[i];

        ll sum = 0;
        for (int j = i - 1; j >= -1; --j) {
            sum += x[j + 1] + bonus[i - j];
            dp[i + 1] = max(dp[i + 1], (j == -1 ? 0 : dp[j]) + sum);
        }
    }

    cout << dp[n] << '\n';
}
