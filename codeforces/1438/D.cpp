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
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    if (n % 2 == 0) {
        if (accumulate(all(a), 0, [](int i, int j) { return i ^ j; }) != 0)
            return cout << "NO\n", 0;
        --n;
    }

    vector<tuple<int, int, int>> ops;
    auto do_op = [&](int i, int j, int k) {
        ops.emplace_back(i, j, k);
        const auto val = a[i] ^ a[j] ^ a[k];
        a[i] = a[j] = a[k] = val;
    };
    for (int i = 0; i + 2 < n; i += 2) do_op(i, i + 1, i + 2);
    for (int i = 0; i + 2 < n; i += 2) do_op(i, i + 1, n - 1);

    cout << "YES\n";
    cout << sz(ops) << '\n';
    for (auto [i, j, k] : ops) cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
}
