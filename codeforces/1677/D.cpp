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

constexpr int mod = 119 << 23 | 1;

int mul(ll x, int y) { return x * y % mod; }

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& x : v) cin >> x;

    rep(i, n - k, n) if (v[i] > 0) return 0;

    int ans = 1;
    rep(i, 0, k) ans = mul(ans, i + 1);
    rep(i, k, n)
        if (v[i - k] == -1) ans = mul(ans, i + 1);
        else if (v[i - k] == 0) ans = mul(ans, k + 1);
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
}
