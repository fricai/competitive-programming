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

constexpr int MX = 62, mod = 998244353;

int add(int x, int y) { return x += y, (x < mod ? x : x - mod); }
int sub(int x, int y) { return x -= y, (x < 0 ? x + mod : x); }
int mul(ll x, int y) { return x * y % mod; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    if (n > MX) return cout << "0\n", 0;

    int f[MX + 1];
    f[0] = 0;
    rep(i, 0, MX) f[i + 1] = max(0ll, min(m + 1 - (1ll << i), 1ll << i)) % mod;

    int dp[MX + 1][MX + 1];
    for (int i = 0; i <= MX; ++i) dp[i][0] = 1;
    for (int j = 1; j <= MX; ++j) dp[0][j] = 0;
    for (int i = 1; i <= MX; ++i)
        for (int j = 1; j <= n; ++j) dp[i][j] = add(dp[i - 1][j], mul(f[i], dp[i - 1][j - 1]));

    cout << dp[MX][n] << '\n';
}
