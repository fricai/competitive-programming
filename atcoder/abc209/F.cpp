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

    int n;
    cin >> n;
    vector<int> h(n);
    for (auto& x : h) cin >> x;

    vector<vector<mint>> g(n);
    g[0] = {1};
    rep(i, 1, n) {
        if (h[i - 1] <= h[i]) {
            // i before i - 1
            vector<mint> sum(i + 1);
            per(j, 0, i) sum[j] = sum[j + 1] + g[i - 1][j];
            g[i] = move(sum);
        }

        if (h[i - 1] >= h[i]) {
            vector<mint> sum(i + 1);
            // i - 1 before i
            rep(j, 0, i) sum[j + 1] = sum[j] + g[i - 1][j];
            if (g[i].empty())
                g[i] = move(sum);
            else
                rep(j, 0, i + 1) g[i][j] += sum[j];
        }
    }

    /*
    rep(i, 0, n) {
        rep(j, 0, i) cerr << g[i][j].val() << ' ';
        cerr << '\n';
    }
    cerr << '\n';
    */

    mint ans = 0;
    rep(j, 0, n) ans += g[n - 1][j];
    cout << ans.val() << '\n';
}
