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
    auto do_op = [&](int i) -> void {
        ops.push_back(i);
        auto rec = [&](const auto& self, int v) -> void {
            assert(a[v] != 0);
            const int L = v << 1 | 0, R = v << 1 | 1;

            if (R >= (1 << h) || (a[L] == 0 && a[R] == 0)) {
                a[v] = 0;
            } else {
                if (a[L] > a[R]) {
                    a[v] = a[L];
                    self(self, L);
                } else {
                    a[v] = a[R];
                    self(self, R);
                }
            }
        };
        rec(rec, i);
    };

    auto get_path = [&](int i) -> vector<int> {
        vector<int> path;
        for (int v = i; v < (1 << h);) {
            if (a[v] == 0) break;
            path.push_back(v);
            const int L = v << 1 | 0, R = v << 1 | 1;
            if ((R < (1 << h)) && a[L] > a[R]) {
                v = L;
            } else {
                v = R;
            }
        }
        return path;
    };

    rep(i, 1, 1 << g) {
        const int d = 31 ^ __builtin_clz(i);
        while (true) {
            auto p = get_path(i);
            if (sz(p) == g - d) break;
            do_op(i);
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
