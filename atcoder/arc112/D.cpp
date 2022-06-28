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

#include <atcoder/dsu>

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<string> g(h);
    for (auto& s : g) cin >> s;

    atcoder::dsu D(h + w);
    g[0][0] = g[0][w - 1] = g[h - 1][w - 1] = g[h - 1][0] = '#';
    rep(i, 0, h) rep(j, 0, w) if (g[i][j] == '#') D.merge(i, j + h);

    vector<int> a(h + w), b(w + h);
    rep(i, 0, h) a[D.leader(i)] = 1;
    rep(j, 0, w) b[D.leader(j + h)] = 1;
    cout << min(accumulate(all(a), 0), accumulate(all(b), 0)) - 1 << '\n';
}
