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

constexpr int mod = 1e9 + 7, N = 2e5 + 20;
constexpr int mul(ll x, int y) { return x * y % mod; }
constexpr void inc(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}
constexpr void dec(int& x, int y) {
    x -= y;
    if (x < 0) x += mod;
}
constexpr int bpow(ll a, ll b) {
    ll res = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

const auto fac = []() {
    array<int, N> fac;
    fac[0] = 1;
    rep(i, 1, N) fac[i] = mul(i, fac[i - 1]);
    return fac;
}();
const auto fac_inv = []() {
    array<int, N> fac_inv;
    fac_inv[N - 1] = bpow(fac[N - 1], mod - 2);
    per(i, 1, N) fac_inv[i - 1] = mul(i, fac_inv[i]);
    return fac_inv;
}();

constexpr int C(int n, int r) {
    return 0 <= r && r <= n ? mul(fac[n], mul(fac_inv[r], fac_inv[n - r])) : 0;
}

constexpr int C_inv(int n, int r) {
    assert(0 <= r && r <= n);
    return mul(fac_inv[n], mul(fac[r], fac[n - r]));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int ans = 0;
        for (int m = 0, high = (n + k - 1) / k; m <= high; ++m)
            inc(ans, mul(C(n - (m - 1) * (k - 1), m), C_inv(n, m)));
        cout << ans << '\n';
    }
}
