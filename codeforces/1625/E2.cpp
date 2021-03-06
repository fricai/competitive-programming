#include <bits/stdc++.h>

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


#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


using S = ll;
S e() { return 0; }
S op(S a, S b) { return a + b; }
using st = atcoder::segtree<S, op, e>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	string s; cin >> s;

	vector<int> stk;
	vector<int> nxt(n, -1);
	rep(i, 0, n) {
		if (s[i] == '(') stk.push_back(i);
		if (s[i] == ')') {
			if (stk.empty()) continue;
			nxt[stk.back()] = i;
			stk.pop_back();
		}
	}

	auto C = [&](ll x) { return x * (x - 1) / 2; };

	st t(n);
	vector<int> dep(n, -1), deg(n);
	vector<int> p(n, -1);
	auto dfs = [&](const auto &self, int u) -> void {
		assert(~nxt[u]);
		for (int v = u + 1; v < nxt[u]; v = nxt[v] + 1) {
			dep[v] = dep[u] + 1;
			p[v] = u;
			self(self, v);
			++deg[u];
		}
		t.set(u, 1 + C(deg[u]));
	};

	for (int i = 0; i < n; ++i) {
		if (~nxt[i]) {
			dep[i] = 0;
			dfs(dfs, i);
			i = nxt[i];
		}
	}

	vector<vector<int>> lev(n);
	rep(i, 0, n) if (~dep[i]) lev[dep[i]].push_back(i);
	vector<st> z(n);
	rep(d, 0, n) z[d] = st(vector(sz(lev[d]), 1ll));

	while (q--) {
		int type, l, r; cin >> type >> l >> r; --l;

		int d = dep[l];
		if (type == 2) {
			assert(~d);
			int x = lower_bound(all(lev[d]), l) - begin(lev[d]);
			int y = lower_bound(all(lev[d]), r) - begin(lev[d]);

			cout << t.prod(l, r) + C(z[d].prod(x, y)) << '\n';
		} else {
			int x = lower_bound(all(lev[d]), l) - begin(lev[d]);
			z[d].set(x, 0);
			t.set(l, 0);
			if (~p[l]) {
				--deg[p[l]];
				t.set(p[l], 1 + C(deg[p[l]]));
			}
		}
	}
}