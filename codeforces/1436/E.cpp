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

template <class T, T id = T{}>
struct rmq {
    int n;
    vector<T> t;

    static constexpr int pw(int n) {
        int sz = 1;
        while (sz < n) sz <<= 1;
        return sz;
    }

    explicit rmq(int _n) : n{pw(_n)}, t(n << 1, id) {}

    T query(int l, int r) const {
        T res = id;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(t[l++], res);
            if (r & 1) res = min(res, t[--r]);
        }
        return res;
    }

    void update(int p, T val) {
        for (t[p += n] = val; p >>= 1;) t[p] = min(t[p << 1], t[p << 1 | 1]);
    }
    T get(int p) const { return t[p + n]; }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x, --x;

    if (*max_element(all(a)) == 0) return cout << "1\n", 0;

    constexpr int inf = 1e9;
    rmq<int, inf> tr(n);
    rep(i, 0, n) tr.update(i, -1);

    vector<uint8_t> exists(n + 2);
    exists[0] = true;
    rep(i, 0, n) {
        const auto x = a[i];
        // last occurrence of [0...x) in < i is after p
        exists[x] |= tr.query(0, x) > tr.get(x);
        tr.update(x, i);
    }
    rep(x, 1, n) { exists[x] |= tr.query(0, x) > tr.get(x); }
    if (tr.query(0, n) > -1) exists[n] = true;

    int ans = 0;
    while (exists[ans]) ++ans;
    cout << ans + 1 << '\n';
}
