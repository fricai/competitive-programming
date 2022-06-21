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
    vector<int> s(n), g(n);
    rep(i, 0, n) cin >> s[i] >> g[i];

    vector<int> mxl(n), mxr(n);
    rep(i, 0, n) {
        mxl[i] = s[i] + g[i];
        if (i > 0) uin(mxl[i], 1 + mxl[i - 1]);
    }
    per(i, 0, n) {
        mxr[i] = s[i] + g[i];
        if (i + 1 < n) uin(mxr[i], 1 + mxr[i + 1]);
    }

    vector<int> res(n);
    rep(i, 0, n) {
        res[i] = min(mxl[i], mxr[i]);
        if (s[i] > res[i]) return cout << "-1\n", 0;
    }

    cout << accumulate(all(res), -accumulate(all(s), 0ll)) << '\n';
    for (auto x : res) cout << x << ' ';
    cout << '\n';
}
