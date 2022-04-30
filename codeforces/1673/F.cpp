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

constexpr int B = 5, N = 1 << B;
int g[N][N];
pair<int, int> inv[N * N];

signed main() {
    ios::sync_with_stdio(false);

    rep(i, 0, N) rep(j, 0, N) {
        const auto one = i ^ (i >> 1);
        const auto two = j ^ (j >> 1);

        g[i][j] = 0;
        rep(x, 0, B) g[i][j] |= (one & (1 << x)) << x | (two & (1 << x)) << (x + 1);
    }

    rep(i, 0, N) rep(j, 0, N) inv[g[i][j]] = {i, j};

    int n, k;
    cin >> n >> k;
    rep(i, 0, n) {
        rep(j, 0, n - 1) cout << (g[i][j] ^ g[i][j + 1]) << ' ';
        cout << endl;
    }
    rep(i, 0, n - 1) {
        rep(j, 0, n) cout << (g[i][j] ^ g[i + 1][j]) << ' ';
        cout << endl;
    }

    int cur = 0;
    rep(i, 0, k) {
        int del;
        cin >> del;
        cur ^= del;

        const auto [x, y] = inv[cur];
        cout << x + 1 << ' ' << y + 1 << endl;
    }
}
