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

constexpr int mod = 1e9 + 7, X = 4e4 + 10;

int dp[X];

int solve() {
    int n;
    cin >> n;
    return dp[n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> pal;
    rep(i, 1, X) {
        const auto s = to_string(i);
        const string t(rall(s));
        if (s == t) pal.push_back(i);
    }

    dp[0] = 1;
    for (auto x : pal) rep(i, x, X) {
            dp[i] += dp[i - x];
            if (dp[i] >= mod) dp[i] -= mod;
        }

    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
}
