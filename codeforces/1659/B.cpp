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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> v;
        {
            string s;
            cin >> s;
            for (const auto& c : s) v.push_back(c - '0');
        }

        int flips = 0;
        vector<int> f(n);
        for (int i = 0; i < n && flips < k; ++i) {
            if ((v[i] ^ k) & 1) {
            } else {
                ++flips;
                ++f[i];
            }
        }

        if (flips < k) {
            // we need to do (k - flips) more flips
            // assert(count(all(v), 1) == n);
            f.back() += k - flips;
        }
        rep(i, 0, n) v[i] ^= (k - f[i]) & 1;
        for (auto x : v) cout << x;
        cout << '\n';
        for (auto x : f) cout << x << ' ';
        cout << '\n';
    }
}
