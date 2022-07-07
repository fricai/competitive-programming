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

int solve() {
    int d, mod;
    cin >> d >> mod;

    // equivalent condition is that MSB(a[i]) is strictly increasing
    // dp[n][i] = number of sequences of length n with last element having MSB i

    const int max_i = 31 ^ __builtin_clz(d);

    vector dp(max_i + 2, vector(max_i + 1, 0ll));
    vector<ll> opt(max_i + 2);

    for (int msb = 0; msb <= max_i; ++msb) {
        opt[msb] = min(d + 1, 2 << msb) - (1 << msb);
        dp[1][msb] = opt[msb];
        assert((1 << msb) <= d);
    }

    for (int len = 2; len <= max_i + 1; ++len) {
        for (int msb = 0; msb <= max_i; ++msb) {
            for (int prev_msb = 0; prev_msb < msb; ++prev_msb) {
                (dp[len][msb] += dp[len - 1][prev_msb] * opt[msb]) %= mod;
            }
        }
    }

    int ans = 0;
    for (int len = 1; len <= max_i + 1; ++len)
        for (int msb = 0; msb <= max_i; ++msb) ans = (ans + dp[len][msb]) % mod;
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
}
