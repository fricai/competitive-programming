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

constexpr int D = 19;
ll ten[D];

ll solve() {
    ll n;
    cin >> n;

    const int len = sz(to_string(n));
  
    ll ans = ten[len - 1] - 1;
    for (int d = 1; d < len; ++d) {
        if (len % d != 0) continue;
        // each block has length d
        const auto M = (ten[len] - 1) / (ten[d] - 1);
        uax(ans, n - (n % M));
    }
    assert(ans > 0);
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ten[0] = 1;
    rep(i, 1, D) ten[i] = 10 * ten[i - 1];

    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
}
