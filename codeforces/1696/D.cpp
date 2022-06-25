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


#include <algorithm>
#include <cassert>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder


constexpr int inf = 1e9;
using S = int;
S op(S a, S b) { return min(a, b); }
S e() { return inf; }

ll solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x, --x;

    vector<int> pl(n), pg(n);
    // pl[i] < i, pr[i] < i
    // a[pl[i]] < a[i], a[pr[i]] > a[i]
    rep(i, 0, n) {
        pl[i] = i - 1;
        while (pl[i] >= 0 && a[pl[i]] >= a[i]) pl[i] = pl[pl[i]];
    }
    rep(i, 0, n) {
        pg[i] = i - 1;
        while (pg[i] >= 0 && a[pg[i]] <= a[i]) pg[i] = pg[pg[i]];
    }

    vector<int> nl(n), ng(n);
    per(i, 0, n) {
        nl[i] = i + 1;
        while (nl[i] < n && a[nl[i]] >= a[i]) nl[i] = nl[nl[i]];
    }
    per(i, 0, n) {
        ng[i] = i + 1;
        while (ng[i] < n && a[ng[i]] <= a[i]) ng[i] = ng[ng[i]];
    }
    rep(i, 0, n) {
        assert(pl[i] < 0 || a[pl[i]] < a[i]);
        assert(pg[i] < 0 || a[pg[i]] > a[i]);
        assert(nl[i] == n || a[nl[i]] < a[i]);
        assert(ng[i] == n || a[ng[i]] > a[i]);
    }

    vector<vector<int>> gl(n), gg(n);
    rep(i, 0, n) {
        if (nl[i] < n) gl[nl[i]].push_back(i);
        if (ng[i] < n) gg[ng[i]].push_back(i);
    }

    vector<int> dp(n, inf);
    dp[0] = 0;
    atcoder::segtree<S, op, e> tl(n), tg(n);
    tl.set(0, 0);
    tg.set(0, 0);
    rep(i, 1, n) {
        for (auto j : gl[i]) tg.set(j, e());
        for (auto j : gg[i]) tl.set(j, e());

        dp[i] = min(1 + tl.prod(pl[i] + 1, i), 1 + tg.prod(pg[i] + 1, i));
        /*
        int cur_mn = a[i], cur_mx = a[i];
        per(j, 0, i) {
            uin(cur_mn, a[j]);
            uax(cur_mx, a[j]);

            if ((cur_mn == a[i] && cur_mx == a[j]) || (cur_mn == a[j] && cur_mx == a[i]))
                dp[i] = min(dp[i], 1 + dp[j]);
        }
        */
        tl.set(i, dp[i]);
        tg.set(i, dp[i]);
    }
    return dp[n - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
}
