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

constexpr int mod = 1e9 + 7, M = 20, K = 5;
int add(int x, int y) { return x += y, x < mod ? x : x - mod; }
int sub(int x, int y) { return x -= y, x < 0 ? x + mod : x; }
void inc(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    {
        string s;
        cin >> s;
        rep(i, 0, n) v[i] = s[i] - '0';
    }

    vector dp(n + 1, vector(1 << M, 0));
    rep(i, 0, n + 1) dp[i][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        rep(S, 0, 1 << M) {
            int cur = 0;
            for (int j = i; j < n; ++j) {
                cur = 2 * cur + v[j];
                if (cur == 0) continue;
                if (cur > M) break;
                if (~S >> (cur - 1) & 1) continue;
                inc(dp[i][S], add(dp[j + 1][S], dp[j + 1][S ^ (1 << (cur - 1))]));
            }
        }
    }

    int ans = 0;
    rep(i, 0, n) rep(j, 0, M) inc(ans, dp[i][(1 << (j + 1)) - 1]);
    cout << ans << '\n';
}
