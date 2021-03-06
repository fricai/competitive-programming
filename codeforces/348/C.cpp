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

    int n, m, q;
    cin >> n >> m >> q;

    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    constexpr int MAG = 250;
    // O(qr + q MAG + m MAG), r = |S| / MAG, |S| = sum(|S_i|)
    // O(q |S| / MAG + (q + m) MAG
    // => MAG = sqrt(q |S|/(q + m)) = sqrt(0.5 * 10^5) = ~223

    vector<int> heavy, heavy_idx(m, -1);

    vector<vector<int>> s(m);
    {
        int i = 0;
        for (auto& x : s) {
            int k;
            cin >> k;
            x.resize(k);
            for (auto& y : x) cin >> y, --y;
            sort(all(x));

            if (k >= MAG) {
                heavy_idx[i] = sz(heavy);
                heavy.push_back(i);
            }
            ++i;
        }
    }

    const int r = sz(heavy);
    vector<ll> heavy_sum(r, 0);
    rep(i, 0, r) for (auto x : s[heavy[i]]) heavy_sum[i] += a[x];

    vector g(m, vector(r, 0));
    {
        vector<int> buf;
        buf.reserve(n);
        rep(i, 0, m) {
            rep(j, 0, r) {
                buf.clear();
                set_intersection(all(s[i]), all(s[heavy[j]]), back_inserter(buf));
                g[i][j] = sz(buf);
            }
        }
    }

    vector<ll> lazy_heavy(r, 0);

    while (q--) {
        char type;
        int k;
        cin >> type >> k;
        --k;
        if (type == '?') {
            ll ans = 0;
            if (heavy_idx[k] == -1) {
                for (auto i : s[k]) ans += a[i];
            } else {
                ans = heavy_sum[heavy_idx[k]];
            }
            rep(j, 0, r) ans += g[k][j] * lazy_heavy[j];
            cout << ans << '\n';
        } else {
            ll x;
            cin >> x;
            if (heavy_idx[k] == -1) {
                // light set
                for (auto i : s[k]) a[i] += x;
                rep(j, 0, r) heavy_sum[j] += x * g[k][j];
            } else {
                // how to handle this?
                lazy_heavy[heavy_idx[k]] += x;
            }
        }
    }
}
