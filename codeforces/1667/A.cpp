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
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    ll ans = 2e18;
    for (int zero = 0; zero < n; ++zero) {
        vector<ll> b(n, 0);
        if (zero - 1 >= 0) {
            b[zero - 1] = 1;
            for (int i = zero - 2; i >= 0; --i) b[i] = 1 + a[i + 1] * b[i + 1] / a[i];
        }
        if (zero + 1 < n) {
            b[zero + 1] = 1;
            for (int i = zero + 2; i < n; ++i) b[i] = 1 + a[i - 1] * b[i - 1] / a[i];
        }
        uin(ans, accumulate(all(b), 0ll));
    }
    cout << ans << '\n';
}
