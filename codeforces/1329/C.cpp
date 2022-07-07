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

void solve() {
    int h, g;
    cin >> h >> g;
    vector<int> a((1 << h) - 1);
    for (auto& x : a) cin >> x;
    a.insert(begin(a), 0);

    vector<int> ops;

    auto get_path = [&](int i) -> vector<int> {
        vector<int> path;
        for (int v = i; v < (1 << h);) {
            if (a[v] == 0) break;
            path.push_back(v);
            const int L = v << 1 | 0, R = v << 1 | 1;
            v = ((R < (1 << h)) && (a[L] > a[R])) ? L : R;
        }
        return path;
    };

    rep(i, 1, 1 << g) {
        const int d = 31 ^ __builtin_clz(i);
        while (true) {
            const auto p = get_path(i);
            if (sz(p) == g - d) break;
            assert(p[0] == i);
            rep(j, 1, sz(p)) a[p[j - 1]] = a[p[j]];
            a[p.back()] = 0;
            ops.push_back(i);
        }
    }

    assert(sz(ops) == (1 << h) - (1 << g));
    cout << accumulate(all(a), 0ll) << '\n';
    for (auto x : ops) cout << x << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
