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

constexpr int NM = 8;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(m));
    for (auto& v : a)
        for (auto& x : v) cin >> x;

    vector<int> cmp(n * m);
    rep(i, 0, n) rep(j, 0, m) cmp[i * m + j] = a[i][j];

    sort(all(cmp));
    cmp.erase(unique(all(cmp)), end(cmp));

    for (auto& v : a)
        for (auto& x : v) x = lower_bound(all(cmp), x) - begin(cmp);

    vector<vector<int>> r(n), c(m);
    rep(i, 0, n) rep(j, 0, m) r[i].push_back(a[i][j]);
    rep(i, 0, n) rep(j, 0, m) c[j].push_back(a[i][j]);

    for (auto& v : r) {
        sort(all(v));
        v.erase(unique(all(v)), end(v));
    }
    for (auto& v : c) {
        sort(all(v));
        v.erase(unique(all(v)), end(v));
    }

    rep(i, 0, n) {
        rep(j, 0, m) {
            const int pos_r = lower_bound(all(r[i]), a[i][j]) - begin(r[i]);
            const int pos_c = lower_bound(all(c[j]), a[i][j]) - begin(c[j]);

            cout << max(pos_r, pos_c) + max(sz(r[i]) - pos_r, sz(c[j]) - pos_c) << ' ';
        }
        cout << '\n';
    }
}
