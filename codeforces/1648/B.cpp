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
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    vector<int> f(2 * c + 1), fp(2 * c + 1);
    for (auto x : a) f[x] = 1;
    partial_sum(all(f), begin(fp));

    for (int a = 1; a <= c; ++a) {
        if (f[a]) continue;
        for (int x = 1; x * a <= c; ++x)
            if (f[x] && fp[x * (a + 1) - 1] != fp[x * a - 1]) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) cout << (solve() ? "Yes" : "No") << '\n';
}
