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

    constexpr array<int, 10> pin_to_col = {3, 2, 4, 1, 3, 5, 0, 2, 4, 6};

    string s;
    cin >> s;

    array<bool, 10> up{};
    rep(i, 0, 10) up[i] = s[i] == '1' ? true : false;

    array<int, 7> col_up{};
    rep(i, 0, 10) col_up[pin_to_col[i]] += up[i];

    cout << (!up[0] &&
                     [&]() {
                         rep(i, 0, 7) rep(j, 0, i - 1) {
                             if (col_up[i] && col_up[j]) {
                                 rep(k, j + 1, i) if (!col_up[k]) return true;
                             }
                         }
                         return false;
                     }()
                 ? "Yes"
                 : "No")
         << '\n';
}
