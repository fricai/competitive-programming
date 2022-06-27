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

#include <atcoder/modint>
using mint = atcoder::modint1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> vals;
    for (int x = 1; x * x <= n; ++x) vals.push_back(x), vals.push_back(n / x);
    sort(rall(vals));
    vals.erase(unique(all(vals)), end(vals));

    const int m = sz(vals);
    assert(vals[0] == n);
    assert(vals[m - 1] == 1);

    vector g(k + 2, vector<mint>(m + 1));

    rep(i, 0, m) g[2][i] = vals[i];
    for (int l = 3; l <= k + 1; ++l) {
        int j = 0;
        per(i, 0, m) {
            g[l][i] = g[l][i + 1];
            while (j < m && n / vals[i] < vals[j] + 1) {
                const auto z = vals[j];
                g[l][i] += (n / z - n / (z + 1)) * g[l - 1][j];
                ++j;
            }
        }
        assert(j == m);
    }

    cout << g[k + 1][0].val() << '\n';
}
