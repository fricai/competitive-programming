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

    int n, m;
    cin >> n >> m;

    atcoder::dsu g(n + m);
    rep(i, 0, n + m) {
        int p;
        cin >> p;
        g.merge(i, p - 1);
    }

    auto v = g.groups();

    int k = sz(v), only_n = 0, only_m = 0;
    for (auto x : v) {
        if (sz(x) > 1 && *max_element(all(x)) < n) ++only_n;
        if (sz(x) > 1 && *min_element(all(x)) >= n) ++only_m;
    }
    cout << n + m - k + 2 * max(only_n, only_m) << '\n';
}
