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

#include <atcoder/dsu>
#include <atcoder/modint>
using mint = atcoder::modint1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector a(n, vector<int>(n));
    rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];

    atcoder::dsu D(n);
    rep(i, 0, n) rep(j, 0, i) {
        if (a[i][j] != 1) continue;
        if (D.same(i, j)) return cout << 0 << '\n', 0;
        D.merge(i, j);
    }

    vector<int> v;
    rep(i, 0, n) if (D.leader(i) == i) v.push_back(i);
    const int m = sz(v);
    auto hsh = [&](int i) { return lower_bound(all(v), D.leader(i)) - begin(v); };

    vector mat(m, valarray<mint>(m));
    rep(i, 0, n) rep(j, 0, n) if (a[i][j] == -1)-- mat[hsh(i)][hsh(j)];
    rep(i, 0, m) mat[i][i] -= accumulate(all(mat[i]), mint(0));

    mint res = 1;
    rep(i, 0, m - 1) {
        res *= mat[i][i];
        if (mat[i][i] == 0) break;
        const auto inv_val = mat[i][i].inv();
        mat[i] *= inv_val;
        rep(j, i + 1, m - 1) {
            const auto to_sub = mat[j][i] * mat[i];
            mat[j] -= to_sub;
        }
    }

    cout << res.val() << '\n';
}
