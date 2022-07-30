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

#include <atcoder/fenwicktree>

auto inversions(vector<int> v) {
    const int r = [&]() {
        auto cmp = v;
        sort(all(cmp));
        cmp.erase(unique(all(cmp)), end(cmp));
        for (auto& x : v) x = lower_bound(all(cmp), x) - begin(cmp);
        return sz(cmp);
    }();

    atcoder::fenwick_tree<int> t(r);

    ll res = 0;
    for (auto x : v) {
        res += t.sum(x + 1, r);
        t.add(x, +1);
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> c(n), a(n);
    for (auto& x : c) cin >> x, --x;
    for (auto& x : a) cin >> x;

    vector<vector<int>> st(n);
    rep(i, 0, n) st[c[i]].push_back(a[i]);

    auto res = inversions(a);

    for (auto& v : st) res -= inversions(v);

    cout << res << '\n';
}
