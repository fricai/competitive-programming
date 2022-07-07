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
    ll ans = 1;
    for (int msb = 0; msb <= max_i; ++msb)
        ans = ans * (min(d + 1, 2 << msb) - (1 << msb) + 1) % mod;
    --ans;
    if (ans < 0) ans += mod;
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
}
