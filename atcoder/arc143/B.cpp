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

/*
ll brute(int n) {
    vector<int> v(n * n);
    iota(all(v), 1);

    ll ans = 0;
    int iteration = 0, cnt = 0;
    do {
        vector<int> row(n, n * n), col(n, 0);
        rep(i, 0, n) rep(j, 0, n) uin(row[i], v[n * i + j]);
        rep(i, 0, n) rep(j, 0, n) uax(col[j], v[n * i + j]);

        bool valid = true;
        rep(i, 0, n) {
            rep(j, 0, n) {
                const auto x = v[n * i + j];
                if (!(x > row[i] || x < col[j])) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        ans += valid;

        sort(all(row));
        if (valid) {
            for (auto x : col) assert(!binary_search(all(row), x));

            if (false) {
                rep(i, 0, n) {
                    rep(j, 0, n) { cerr << v[n * i + j] << ' '; }
                    cerr << '\n';
                }
                cerr << '\n';
                ++cnt;
            }
        } else {
            int one = 0;
            for (auto x : col) one += binary_search(all(row), x);
            assert(one == 1);
        }

        if (iteration % 1000000 == 0) cerr << ans << '\n';
        ++iteration;
    } while (next_permutation(all(v)));
    return ans;
}
*/

#include <atcoder/modint>
constexpr int mod = 998244353;
using mint = atcoder::static_modint<mod>;

constexpr int X = 500 * 500 + 10;
mint f[X], fi[X];
mint C(int n, int r) {
    return r < 0 || r > n ? mint(0) : f[n] * fi[r] * fi[n - r];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    f[0] = 1;
    rep(i, 1, X) f[i] = i * f[i - 1];
    fi[X - 1] = f[X - 1].inv();
    per(i, 1, X) fi[i - 1] = i * fi[i];

    int n;
    cin >> n;

    mint ans = 0;
    for (int x = 1; x <= n * n; ++x)
        ans += C(x - 1, n - 1) * C(n * n - x, n - 1);
    ans *= f[n - 1] * f[n - 1] * f[(n - 1) * (n - 1)] * n * n;
    ans = f[n * n] - ans;
    cout << ans.val() << '\n';
}
