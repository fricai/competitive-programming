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

struct H {
    using ull = uint64_t;
    ull x;
    H(ull x = 0) : x(x) {}
#define OP(O, A, B)                                         \
    H operator O(H o) const {                               \
        ull r = x;                                          \
        asm(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); \
        return r;                                           \
    }
    OP(+, , "d"(o.x));
    OP(*, "mul %1\n", "r"(o.x) : "rdx");
    H operator-(H o) const { return *this + ~o.x; }
    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator<(H o) const { return get() < o.get(); }
};
static const H C = rng();  // (order ~ 3e9; random also ok)

constexpr int N = 1e5 + 10;
const auto pw = []() {
    array<H, N> tmp;
    tmp[0] = 1;
    rep(i, 1, N) tmp[i] = C * tmp[i - 1];
    return tmp;
}();
const auto pw_sum = []() {
    // pw_sum[i] = 1 + ... + C^(i - 1)
    array<H, N> tmp;
    tmp[0] = 0;
    // tmp[i + 1] = 1 + C + .. + C^i = 1 + C * (1 + ... + C^(i - 1)) = 1 + C * tmp[i]
    rep(i, 1, N) tmp[i] = C * tmp[i - 1] + 1;
    return tmp;
}();


#include <algorithm>
#include <cassert>
#include <iostream>
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

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder


struct S {
    H hsh;
    int len;
};
S op(S a, S b) { return {a.hsh * pw[b.len] + b.hsh, a.len + b.len}; }
S e() { return {0, 0}; }

static const H A = (1ULL << 32);
using F = H;
S mapping(F f, S x) { return f < A ? S{f * pw_sum[x.len], x.len} : x; }
F composition(F f, F g) { return f < A ? f : g; }
F id() { return A; }

using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

H f(H a, ll b) {
    /*
    H res = 0;
    rep(i, 0, b) res = a * res + 1;
    return res;
    */

    if (b == 0) return 0;
    return b & 1 ? a * f(a, b - 1) + 1 : (a + 1) * f(a * a, b >> 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int V = 10;
    array<H, V> mp;
    rep(i, 0, V) {
        while (true) {
            mp[i] = rng();
            bool valid = true;
            rep(j, 0, i) if (mp[i] == mp[j]) valid = false;
            if (valid) break;
        }
        assert(mp[i] < A);
    }

    int n, m, k;
    cin >> n >> m >> k;

    segtree t(n);
    rep(i, 0, n) {
        char c;
        cin >> c;
        t.set(i, {mp[c - '0'], 1});
    }

    rep(i, 0, m + k) {
        int type;
        cin >> type;

        int l, r;
        cin >> l >> r;
        --l;

        if (type == 1) {
            int c;
            cin >> c;
            t.apply(l, r, mp[c]);
        } else {
            int d;
            cin >> d;
            assert(1 <= d && d <= r - l);

            const int mod = (r - l) % d;
            const int del = (r - l) / d;
            assert(l + d * del == r - mod);

            const auto full = t.prod(l, r);
            const auto most = S{t.prod(l, l + d).hsh * f(pw[d], del), d * del};
            const auto back = t.prod(r - mod, r);
            const auto front = t.prod(l, l + mod);

            cout << (front.hsh == back.hsh && full.hsh == op(most, back).hsh ? "YES" : "NO")
                 << '\n';
        }
    }
}
