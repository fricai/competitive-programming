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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto& x : v) cin >> x;

    ll sum = 0, mn_time = 0;
    rep(i, 0, n) {
        sum += v[i];
        uax(mn_time, (sum + i) / (i + 1));
    }

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        cout << (t < mn_time ? -1ll : (sum + t - 1) / t) << '\n';
    }
}
