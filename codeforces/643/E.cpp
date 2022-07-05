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

constexpr int H = 50;

template <class T, int N>
constexpr auto get_array(T x) {
    array<T, N> a;
    fill(all(a), x);
    return a;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    vector<int> par(1, -1);
    vector dp(1, get_array<double, H>(1.0));
    // dp[0][x] <= 1 is 1

    cout << fixed << setprecision(10);
    while (q--) {
        int type, v;
        cin >> type >> v;
        --v;

        if (type == 1) {
            par.push_back(v);
            dp.push_back(get_array<double, H>(1.0));

            {
                array<array<double, H>, 2> old;
                old[0] = dp[v];
                dp[v][0] *= 0.5;
                rep(i, 1, H) {
                    if (v == 0) break;
                    const int u = par[v];
                    old[i & 1] = dp[u];
                    rep(x, 1, H) dp[u][x] *= (1 + dp[v][x - 1]) / (1 + old[~i & 1][x - 1]);
                    v = u;
                }
            }
        } else {
            double ans = 0;
            rep(h, 1, H) ans += h * (dp[v][h] - dp[v][h - 1]);
            cout << ans << '\n';
        }
    }
}
