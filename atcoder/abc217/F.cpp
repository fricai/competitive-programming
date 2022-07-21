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
using mint = atcoder::modint998244353;

constexpr int N = 210;
mint f[N], fi[N];
mint C(int n, int r) {
    assert(0 <= r && r <= n);
    return f[n] * fi[n - r] * fi[r];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    f[0] = 1;
    rep(i, 1, N) f[i] = mint::raw(i) * f[i - 1];
    fi[N - 1] = f[N - 1].inv();
    per(i, 1, N) fi[i - 1] = mint::raw(i) * fi[i];

    int n, m;
    cin >> n >> m;
    n *= 2;

    vector<vector<int>> g(n);
    rep(e, 0, m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        assert(x < y);
        g[x].push_back(y);
    }
    for (auto& v : g) sort(all(v));

    vector dp(n + 1, vector<mint>(n, mint::raw(-1)));
    rep(i, 0, n) dp[i + 1][i] = 1;
    auto rec = [&](const auto& self, int l, int r) -> mint {
        if (dp[l][r].val() < (uint32_t)mint::mod()) return dp[l][r];
        const auto len = r - l + 1;
        assert(len >= 0);
        assert(len % 2 == 0);

        dp[l][r] = 0;
        for (auto o : g[l]) {
            if (o > r) break;
            const auto small = r - o;
            if (small % 2 != 0) continue;
            dp[l][r] += C(len / 2, small / 2) * self(self, l + 1, o - 1) * self(self, o + 1, r);
        }
        return dp[l][r];
    };

    cout << rec(rec, 0, n - 1).val() << '\n';
}
