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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    vector<ll> sum_pref(n + 1), dot_pref(n + 1);
    rep(i, 0, n) {
        sum_pref[i + 1] = sum_pref[i] + a[i];
        dot_pref[i + 1] = dot_pref[i] + i * a[i];
    }

    // [j, i)

    constexpr ll inf = 1e18;
    ll ans = -inf;
    for (int i = 0; i + m <= n; ++i) {
        // [i - m, i)
        ans = max(ans, (dot_pref[i + m] - dot_pref[i]) - (i - 1) * (sum_pref[i + m] - sum_pref[i]));
    }
    cout << ans << '\n';
}

