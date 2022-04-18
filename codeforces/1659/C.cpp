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

constexpr ll inf = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        vector<ll> x(n);
        for (auto& c : x) cin >> c;

        vector<ll> s(n + 1);
        rep(i, 0, n) s[i + 1] = s[i] + x[i];
        x.insert(begin(x), 0);

        ll ans = inf;
        for (int k = 0; k <= n; ++k) {
            uin(ans, a * x[k] + b * (x[k] - (n - k) * x[k] + (s[n] - s[k])));
        }
        cout << ans << '\n';
    }
}
