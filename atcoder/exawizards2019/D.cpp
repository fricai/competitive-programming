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

#include <atcoder/modint>
using mint = atcoder::modint1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> s(n);
    for (auto& x : s) cin >> x;
    sort(rall(s));

    for (auto x : s) cerr << x << ' ';
    cerr << '\n';

    vector dp(n + 1, vector<mint>(x + 1));
    dp[0][x] = 1;
    rep(i, 0, n) {
        for (int y = 0; y <= x; ++y) {
            dp[i + 1][y] += (n - i - 1) * dp[i][y];
            dp[i + 1][y % s[i]] += dp[i][y];
        }
    }

    mint ans = 0;
    for (int y = 0; y <= x; ++y) ans += y * dp[n][y];
    cout << ans.val() << '\n';
}
