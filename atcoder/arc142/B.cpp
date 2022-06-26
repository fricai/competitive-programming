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
    cin >> n;
    vector g(n, vector<int>(n, 0));
    g[0][0] = 1;
    g[0][1] = 3;
    g[1][0] = 4;
    g[1][1] = 2;

    for (int i = 2; i < n; ++i) {
        const int sq = (i + 1) * (i + 1);
        g[i][i] = sq - 1;
        g[i][i - 1] = sq - 2;
        g[i - 1][i] = sq;

        int x = sq - 2;
        for (int j = i - 3; j >= 0; j -= 2) g[i][j] = --x;
        for (int j = i - 2; j >= 0; j -= 2) g[i][j] = --x;
        for (int j = i - 3; j >= 0; j -= 2) g[j][i] = --x;
        for (int j = i - 2; j >= 0; j -= 2) g[j][i] = --x;
    }

    auto check = [](const auto& g) -> bool {
        const int n = g.size();
        auto in_grid = [n](int i, int j) { return 0 <= i && i < n && 0 <= j && j < n; };
        rep(i, 0, n) {
            rep(j, 0, n) {
                int tot = 0, smol = 0;
                auto f = [&](int x, int y) {
                    if (in_grid(x, y)) ++tot, smol += g[x][y] < g[i][j];
                };
                for (auto x : {-1, 0, 1})
                    for (auto y : {-1, 0, 1})
                        if (x != 0 || y != 0) f(i + x, j + y);
                if (2 * smol == tot) return false;
            }
        }
        return true;
    };

    rep(i, 0, n) {
        rep(j, 0, n) cout << g[i][j] << ' ';
        cout << '\n';
    }
    if (!check(g)) cerr << "bad\n";
}
