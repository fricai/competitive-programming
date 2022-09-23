#include <cstdio>
#include <vector>

#include <cassert>

using namespace std;

template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
    int n, sz;
    std::vector<S> t;

   public:
    segtree() : n{0} {}
    explicit segtree(int _n) : n{_n} {
        sz = 1;
        while (sz < n) sz *= 2;
        t.assign(sz << 1, e());
    }

    void set(int p, S x) {  // assign x at position p
        for (t[p += sz] = x; p >>= 1;) t[p] = op(t[p << 1], t[p << 1 | 1]);
    }
    S get(int p) const { return t[p + sz]; }  // return value at position p
    S query(int l, int r) const {             // return [l, r)
        S res_l{e()}, res_r{e()};             // need two for non-commutative operations
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res_l = op(res_l, t[l++]);
            if (r & 1) res_r = op(t[--r], res_r);
        }
        return op(res_l, res_r);
    }
    S root() { return t[1]; }

    template <class F>
    int max_right(int l, F f) const {
        // find max r such that f[l, r) is true but f[l, r] is false
        assert(f(e()));
        if (l == n) return n;
        l += sz;
        S val = e(), nxt_val;
        do {
            // val = f[initial l, current l's right most)
            while (l % 2 == 0) l >>= 1;  // go up until l is a right child
            nxt_val = op(val, t[l]);
            if (!f(nxt_val)) {
                // go down in this block until we find the right index
                while (l < sz) {
                    l <<= 1;
                    if (f(op(val, t[l]))) {
                        val = op(val, t[l]);
                        ++l;
                    }
                }
                return l - sz;
            }
            val = nxt_val;
            ++l;
        } while ((l & (l - 1)) != 0);
        // l isn't a power of two, equivalent to checking if ++l set us to the next block in the
        // same layer or not

        // outer loop finds first block where [l.. that block] evaluates to false
        // inner loop then pinpoints the exact index where it becomes false
        return n;
    }

    template <class F>
    int min_left(int r, F f) const {
        // find min l such that f[l, r) is true but f[l - 1, r) is false
        assert(f(e()));
        if (r == 0) return 0;
        r += sz;
        S val = e(), nxt_val;
        do {
            while (r % 2 == 0) r >>= 1;
            if (r > 1) --r; // the check is important
            nxt_val = op(t[r], val);
            if (!f(nxt_val)) {
                while (r < sz) {
                    r = r << 1 | 1;
                    if (f(op(t[r], val))) {
                        val = op(t[r], val);
                        --r;
                    }
                }
                return r + 1 - sz;
            }
            val = nxt_val;
        } while ((r & (r - 1)) != 0);
        return 0;
    }
};


int op(int a, int b) { return max(a, b); }

int e() { return -1; }

int target;

bool f(int v) { return v < target; }

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &(a[i]));
    }

    segtree<int, op, e> seg(n);
    for (int i = 0; i < n; ++i)
        seg.set(i, a[i]);
    
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x, v;
            scanf("%d %d", &x, &v);
            x--;
            seg.set(x, v);
        } else if (t == 2) {
            int l, r;
            scanf("%d %d", &l, &r);
            l--;
            printf("%d\n", seg.query(l, r));
        } else if (t == 3) {
            int p;
            scanf("%d %d", &p, &target);
            p--;
            printf("%d\n", seg.max_right(p, [](auto x) { return f(x); }) + 1);
        }
    }
}
