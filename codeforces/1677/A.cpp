#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a);)
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

ll solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x : p) cin >> x, --x;

    vector f(n, vector(n, 0));
    for (int c = 0; c < n; ++c) {
        vector vals(begin(p) + c, end(p));
        sort(all(vals));

        f[c][0] = 0;
        for (int a = 1; a <= c; ++a)
            f[c][a] = f[c][a - 1] + (lower_bound(all(vals), p[a - 1]) - begin(vals));
    }

    ll ans = 0;
    for (int a = 0; a < n; ++a) {
        for (int c = a + 1; c + 1 < n; ++c) {
            if (p[a] > p[c]) continue;
            ans += f[c + 1][c] - f[c + 1][a + 1];
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
}
