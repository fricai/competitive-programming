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

constexpr int B = 40;
constexpr ll inf = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;

        vector<ll> a(n);
        for (auto& x : a) cin >> x;

        vector dp(n + 1, array<ll, B>{});
        dp[0][0] = 0;
        // rep(j, 1, B) dp[0][j] = -inf;
        // max cost if you have used the key j times already,
        // 1. it was not part of the last use
        rep(i, 0, n) {
            dp[i + 1][0] = dp[i][0] + a[i] - k;
            rep(j, 1, B) dp[i + 1][j] = max(dp[i][j] + (a[i] >> j) - k, dp[i][j - 1] + (a[i] >> j));
        }

        ll ans = 0;
        rep(i, 0, n + 1) rep(j, 0, B) uax(ans, dp[i][j]);
        cout << ans << '\n';
    }
}
