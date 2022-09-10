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

#include <atcoder/convolution>
#include <atcoder/modint>
using mint = atcoder::modint998244353;
using poly = vector<mint>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    vector<array<poly, 2>> f(n), g;
    rep(i, 0, n) {
        f[i][0] = {1};
        f[i][1].assign(a[i] + 1, 0);
        f[i][1][a[i]] = 1;
    }

    while (n > 1) {
        g.resize((n + 1) / 2);
        for (int i = 0; i + 1 < n; i += 2) {
            auto& v = g[i / 2];
            rep(b, 0, 2) {
                v[b] = atcoder::convolution(f[i][0], f[i + 1][b]);
                auto tmp = atcoder::convolution(f[i][1], f[i + 1][!b]);
                if (tmp.size() > v[b].size()) swap(v[b], tmp);
                rep(j, 0, sz(tmp)) v[b][j] += tmp[j];
            }
        }
        if (n % 2 == 1) g.back() = move(f.back());
        n = (n + 1) / 2;
        swap(f, g);
    }
    cout << (m < sz(f[0][1]) ? f[0][1][m].val() : 0) << '\n';
}
