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
    vector<int> p(n), a(n);
    rep(i, 1, n) cin >> p[i], --p[i];
    for (auto& x : a) cin >> x;

    vector<ll> sub(all(a));
    vector<int> deg(n), leaves(n);
    per(i, 1, n) {
        leaves[i] += deg[i] == 0;
        sub[p[i]] += sub[i];
        ++deg[p[i]];
        leaves[p[i]] += leaves[i];
    }

    ll ans = 0;
    rep(u, 0, n) uax(ans, (sub[u] + leaves[u] - 1) / leaves[u]);
    cout << ans << '\n';
}
