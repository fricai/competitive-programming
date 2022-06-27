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

constexpr int X = 1e5 + 10;
vector<int> r[X], c[X];

ll cnt(vector<int>& r) {
    sort(all(r));

    const int n = r.size();
    ll cur = 0, ans = 0;
    rep(i, 0ll, n) {
        ans += i * r[i] - cur;
        cur += r[i];
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector g(n, vector(m, 0));
    rep(i, 0, n) rep(j, 0, m) cin >> g[i][j];

    rep(i, 0, n) rep(j, 0, m) {
        r[g[i][j]].push_back(i);
        c[g[i][j]].push_back(j);
    }

    ll ans = 0;
    rep(i, 0, X) ans += cnt(r[i]);
    rep(i, 0, X) ans += cnt(c[i]);
    cout << ans << '\n';
}
