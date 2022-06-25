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

bool solve() {
    int n;
    ll m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int k;
    cin >> k;
    vector<int> b(k);
    for (auto& x : b) cin >> x;

    if (accumulate(all(b), 0ll) != accumulate(all(a), 0ll)) return false;

    vector<pair<int, ll>> c, d;
    auto add = [&](auto& c, int x, ll cnt) -> void {
        if (c.empty() || c.back().first != x)
            c.emplace_back(x, cnt);
        else
            c.back().second += cnt;
    };
    for (auto x : a) {
        ll cnt = 1;
        while (x % m == 0) {
            x /= m;
            cnt *= m;
        }
        add(c, x, cnt);
    }
    for (auto x : b) {
        ll cnt = 1;
        while (x % m == 0) {
            x /= m;
            cnt *= m;
        }
        add(d, x, cnt);
    }

    /*
    for (auto [x, y] : c) cerr << complex<ll>(x, y) << ' ';
    cerr << '\n';
    for (auto [x, y] : d) cerr << complex<ll>(x, y) << ' ';
    cerr << '\n';
    */

    return c == d;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) cout << (solve() ? "Yes" : "No") << '\n';
}
