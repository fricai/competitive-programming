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

    int n;

    using U = uint32_t;
    U c;
    cin >> n >> c;

    constexpr int B = 30;
    using SU = uint8_t;
    array<SU, B> a;
    rep(i, 0, B) a[i] = 0b10u;

    rep(i, 0, n) {
        int t;
        U upd;
        cin >> t >> upd;
        rep(j, 0, B) {
            SU v = upd >> j & 1;
            v = v << 1 | v;
            if (t == 1) a[j] &= v;
            if (t == 2) a[j] |= v;
            if (t == 3) a[j] ^= v;
        }

        U new_c = 0;
        rep(j, 0, B) new_c |= (a[j] >> (c >> j & 1) & 1) << j;

        cout << new_c << '\n';
        c = new_c;
    }
}
