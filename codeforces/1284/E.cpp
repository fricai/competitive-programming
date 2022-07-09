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

using point = complex<ll>;
bool upper_half_plane(const point& p) { return imag(p) > 0 || (imag(p) == 0 && real(p) > 0); }
ll cross(const point& a, const point& b) { return imag(conj(a) * b); }

constexpr ll C(ll n, int k) {
    ll res = 1;
    for (int i = 0; i < k; ++i) {
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<point> p(n);
    for (auto& z : p) {
        int x, y;
        cin >> x >> y;
        z = {x, y};
    }

    const auto quads = C(n - 1, 4);

    ll ans = 0;
    rep(i, 0, n) {
        auto q = p;
        q.erase(begin(q) + i);
        for (auto& z : q) z -= p[i];

        sort(all(q), [&](const point& a, const point& b) {
            const auto hpa = upper_half_plane(a);
            if (hpa != upper_half_plane(b)) return hpa;
            return cross(a, b) > 0;
        });

        ll cur = 0;

        {
            int j = 0, del = 0;
            auto inc = [&]() {
                ++j, ++del;
                if (j == n - 1) j = 0;
            };
            for (int i = 0; i < n - 1; ++i) {
                --del;
                if (j == i) inc();
                while (cross(q[i], q[j]) > 0) inc();
                cur += C(del, 3);
            }
        }

        ans += quads - cur;
    }
    cout << ans << '\n';
}
