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
constexpr int mod = 1e9 + 7, MX = 400;
using mint = atcoder::static_modint<mod>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    vector<pair<int, int>> I(n);
    rep(i, 0, n) cin >> I[i].first;
    rep(i, 0, n) cin >> I[i].second;

    vector p(c + 1, vector(MX + 1, mint(0)));
    iota(all(p[0]), mint(1));
    for (int k = 1; k <= c; ++k)
        for (int j = 1; j <= MX; ++j) p[k][j] = p[k][j - 1] + mint(j).pow(k);

    vector<mint> res(c + 1);
    res[0] = 1;
    for (auto [a, b] : I) {
        --a;
        vector<mint> q(c + 1);
        for (int i = 0; i <= c; ++i) q[i] = p[i][b] - p[i][a];

        vector<mint> nxt(c + 1);
        for (int i = 0; i <= c; ++i)
            for (int j = 0; i + j <= c; ++j) nxt[i + j] += res[i] * q[j];
        res = move(nxt);
    }

    cout << res[c].val() << '\n';
}
