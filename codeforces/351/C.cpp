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

constexpr ll inf = 1e18;

struct mat {
    int n;
    vector<vector<ll>> a;
    mat() {}
    explicit mat(int n) : n{n}, a(n, vector(n, inf)) {}
    mat operator*(const mat& b) {
        assert(b.n == n);
        mat c(n);
        rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) uin(c[i][k], a[i][j] + b[j][k]);
        return c;
    }

    vector<ll>& operator[](int i) { return a[i]; }
    const vector<ll>& operator[](int i) const { return a[i]; }
};

template <class T>
T bpow(T a, ll b) {
    assert(b >= 0);
    if (b == 0) return T{};
    T res{a};
    for (--b; b > 0; b >>= 1) {
        if (b & 1) res = res * a;
        a = a * a;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    const int max_bal = 2 * n;
    mat t(max_bal + 1);

    // t[i][j] = min cost to go from i balance to j balance
    //           is this equivalent to going from 0 balanced to j - i balance? no.

    for (int i = 0; i <= max_bal; ++i) {
        vector dp(n + 1, vector(max_bal + 1, inf));
        dp[0][i] = 0;
        for (int len = 1; len <= n; ++len) {
            for (int j = 1; j <= max_bal; ++j) uin(dp[len][j], dp[len - 1][j - 1] + a[len - 1]);
            for (int j = 0; j < max_bal; ++j) uin(dp[len][j], dp[len - 1][j + 1] + b[len - 1]);
        }
        for (int j = 0; j <= max_bal; ++j) t[i][j] = dp[n][j];
    }

    auto res = bpow(t, m);
    cout << res[0][0] << '\n';
}
