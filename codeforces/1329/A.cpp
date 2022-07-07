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

int nope() {
    cout << "-1\n";
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> l(m);
    for (auto& x : l) cin >> x;

    rep(i, 0, m) if (l[i] + i > n) return nope();

    if (accumulate(all(l), 0ll) < n) return nope();

    ll sum = 0;
    vector<int> p(m);

    per(i, 0, m) {
        sum += l[i];
        p[i] = max((ll)i, n - sum);
    }

    for (auto x : p) cout << x + 1 << ' ';
    cout << '\n';
}
