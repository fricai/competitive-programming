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
using mint = atcoder::modint998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    const int S = accumulate(all(a), 0);

    vector f(n + 1, vector<mint>(S + 1));
    f[0][0] = 1;
    auto g = f;
    rep(i, 0, n) {
        for (int x = 0; x <= S; ++x) f[i + 1][x] = 2 * f[i][x];
        for (int x = a[i]; x <= S; ++x) f[i + 1][x] += f[i][x - a[i]];
        for (int x = 0; x <= S; ++x) g[i + 1][x] = g[i][x];
        for (int x = a[i]; x <= S; ++x) g[i + 1][x] += g[i][x - a[i]];
    }

    mint acc = 0;
    for (int i = (S + 1) / 2; i <= S; ++i) acc += f[n][i];

    if (S % 2 == 0) acc -= g[n][S / 2];

    cout << (mint(3).pow(n) - 3 * acc).val() << '\n';
}
