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

auto get(const vector<int>& a) {
    const int n = a.size();
    vector<int> b(n);
    rep(i, 0, n - 1) b[i] = a[i] ^ a[i + 1];
    b[n - 1] = a[n - 1] ^ a[0];
    return b;
}

#include <atcoder/string>

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    auto c = get(a);
    c.push_back(-1);
    {
        const auto tmp = get(b);
        c.insert(end(c), all(tmp));
        c.insert(end(c), all(tmp));
    }

    const auto z = atcoder::z_algorithm(c);
    auto test = [&](int i) {
        if (z[i + n + 1] != n) return;
        cout << n - i << ' ' << (a[0] ^ b[i % n]) << '\n';
    };
    for (int i = n; i > 0; --i) test(i);
}
