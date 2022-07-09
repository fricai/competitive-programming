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
#include <numeric>
#include <string>
#include <vector>

namespace atcoder {

namespace internal {

std::vector<int> sa_naive(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n);
    std::iota(sa.begin(), sa.end(), 0);
    std::sort(sa.begin(), sa.end(), [&](int l, int r) {
        if (l == r) return false;
        while (l < n && r < n) {
            if (s[l] != s[r]) return s[l] < s[r];
            l++;
            r++;
        }
        return l == n;
    });
    return sa;
}

std::vector<int> sa_doubling(const std::vector<int>& s) {
    int n = int(s.size());
    std::vector<int> sa(n), rnk = s, tmp(n);
    std::iota(sa.begin(), sa.end(), 0);
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int x, int y) {
            if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
            int rx = x + k < n ? rnk[x + k] : -1;
            int ry = y + k < n ? rnk[y + k] : -1;
            return rx < ry;
        };
        std::sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        std::swap(tmp, rnk);
    }
    return sa;
}

template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
std::vector<int> sa_is(const std::vector<int>& s, int upper) {
    int n = int(s.size());
    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) {
        if (s[0] < s[1]) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }
    if (n < THRESHOLD_NAIVE) {
        return sa_naive(s);
    }
    if (n < THRESHOLD_DOUBLING) {
        return sa_doubling(s);
    }

    std::vector<int> sa(n);
    std::vector<bool> ls(n);
    for (int i = n - 2; i >= 0; i--) {
        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
    }
    std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
    for (int i = 0; i < n; i++) {
        if (!ls[i]) {
            sum_s[s[i]]++;
        } else {
            sum_l[s[i] + 1]++;
        }
    }
    for (int i = 0; i <= upper; i++) {
        sum_s[i] += sum_l[i];
        if (i < upper) sum_l[i + 1] += sum_s[i];
    }

    auto induce = [&](const std::vector<int>& lms) {
        std::fill(sa.begin(), sa.end(), -1);
        std::vector<int> buf(upper + 1);
        std::copy(sum_s.begin(), sum_s.end(), buf.begin());
        for (auto d : lms) {
            if (d == n) continue;
            sa[buf[s[d]]++] = d;
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        sa[buf[s[n - 1]]++] = n - 1;
        for (int i = 0; i < n; i++) {
            int v = sa[i];
            if (v >= 1 && !ls[v - 1]) {
                sa[buf[s[v - 1]]++] = v - 1;
            }
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        for (int i = n - 1; i >= 0; i--) {
            int v = sa[i];
            if (v >= 1 && ls[v - 1]) {
                sa[--buf[s[v - 1] + 1]] = v - 1;
            }
        }
    };

    std::vector<int> lms_map(n + 1, -1);
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms_map[i] = m++;
        }
    }
    std::vector<int> lms;
    lms.reserve(m);
    for (int i = 1; i < n; i++) {
        if (!ls[i - 1] && ls[i]) {
            lms.push_back(i);
        }
    }

    induce(lms);

    if (m) {
        std::vector<int> sorted_lms;
        sorted_lms.reserve(m);
        for (int v : sa) {
            if (lms_map[v] != -1) sorted_lms.push_back(v);
        }
        std::vector<int> rec_s(m);
        int rec_upper = 0;
        rec_s[lms_map[sorted_lms[0]]] = 0;
        for (int i = 1; i < m; i++) {
            int l = sorted_lms[i - 1], r = sorted_lms[i];
            int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
            int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
            bool same = true;
            if (end_l - l != end_r - r) {
                same = false;
            } else {
                while (l < end_l) {
                    if (s[l] != s[r]) {
                        break;
                    }
                    l++;
                    r++;
                }
                if (l == n || s[l] != s[r]) same = false;
            }
            if (!same) rec_upper++;
            rec_s[lms_map[sorted_lms[i]]] = rec_upper;
        }

        auto rec_sa =
            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

        for (int i = 0; i < m; i++) {
            sorted_lms[i] = lms[rec_sa[i]];
        }
        induce(sorted_lms);
    }
    return sa;
}

}  // namespace internal

std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
    assert(0 <= upper);
    for (int d : s) {
        assert(0 <= d && d <= upper);
    }
    auto sa = internal::sa_is(s, upper);
    return sa;
}

template <class T> std::vector<int> suffix_array(const std::vector<T>& s) {
    int n = int(s.size());
    std::vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
    std::vector<int> s2(n);
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (i && s[idx[i - 1]] != s[idx[i]]) now++;
        s2[idx[i]] = now;
    }
    return internal::sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return internal::sa_is(s2, 255);
}

template <class T>
std::vector<int> lcp_array(const std::vector<T>& s,
                           const std::vector<int>& sa) {
    int n = int(s.size());
    assert(n >= 1);
    std::vector<int> rnk(n);
    for (int i = 0; i < n; i++) {
        rnk[sa[i]] = i;
    }
    std::vector<int> lcp(n - 1);
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (h > 0) h--;
        if (rnk[i] == 0) continue;
        int j = sa[rnk[i] - 1];
        for (; j + h < n && i + h < n; h++) {
            if (s[j + h] != s[i + h]) break;
        }
        lcp[rnk[i] - 1] = h;
    }
    return lcp;
}

std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return lcp_array(s2, sa);
}

template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {
    int n = int(s.size());
    if (n == 0) return {};
    std::vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

std::vector<int> z_algorithm(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}

}  // namespace atcoder


template <class Min>
struct rmq {
    static constexpr int b = 31;
    static constexpr uint32_t all_mask = (1U << b) - 1;
    int n;
    std::vector<uint32_t> mask;
    Min min;
    std::vector<std::vector<int>> jmp;
    static uint32_t lsb(uint32_t x) { return x & -x; }
    static int msb_index(uint32_t x) { return 31 ^ __builtin_clz(x); }

    rmq(int _n, Min _min) : n(_n), mask(n), min(_min) {
        uint32_t curr_mask = 0;
        for (int i = 0; i < n; i++) {
            curr_mask = (curr_mask << 1) & all_mask;
            while (curr_mask) {
                uint32_t l = lsb(curr_mask);
                if (min(i, i - msb_index(l)) == i)
                    curr_mask ^= lsb(curr_mask);
                else
                    break;
            }
            curr_mask |= 1;
            mask[i] = curr_mask;
        }
        auto f = [this](int i) { return small(b * i + b - 1); };
        jmp = std::vector(1, std::vector<int>(n / b));
        int t = 0;
        std::generate(jmp[0].begin(), jmp[0].end(), [&f, &t] { return f(t++); });
        for (int pw = 1, k = 1; pw * 2 <= n / b; pw *= 2, ++k) {
            jmp.emplace_back(n / b - pw * 2 + 1);
            for (int j = 0; j < (int)jmp[k].size(); ++j)
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    int query(int l, int r) const {
        --r;
        if (r - l + 1 <= b) return small(r, r - l + 1);
        int ans = min(small(l + b - 1), small(r));
        int x = l / b + 1, y = r / b;
        if (x < y) {
            int dep = msb_index(y - x);
            ans = min(ans, min(jmp[dep][x], jmp[dep][y - (1 << dep)]));
        }
        return ans;
    }
    int small(int r, int size = b) const {
        int dist_from_r = msb_index(mask[r] & ((1U << size) - 1));
        return r - dist_from_r;
    }
};

template <class T, T id = T{}>
struct range_update_point_query {
    int n;
    vector<T> t;
    range_update_point_query() : n{0} {}
    explicit range_update_point_query(int _n) {
        n = 1;
        while (n < _n) n <<= 1;
        t.resize(n << 1, id);
    }
    T get(int p) {
        T res = id;
        for (p += n; p > 0; p >>= 1) res += t[p];
        return res;
    }
    void update(int l, int r, T del) {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) t[l++] += del;
            if (r & 1) t[--r] += del;
        }
    }
    void push_all() {
        rep(i, 1, n) {
            t[i << 1 | 0] += t[i];
            t[i << 1 | 1] += t[i];
            t[i] = id;
        }
    }
    T leaf(int p) { return t[p + n]; }
};

template <typename I, typename P, bool b>
I bin_search_split(I l, I r, const P& predicate) {
    --l, ++r;
    while (r - l > 1) {
        auto mid = l + (r - l) / 2;
        if (predicate(mid))
            l = mid;
        else
            r = mid;
    }
    if constexpr (b) {
        return r;
    } else {
        return l;
    }
}

// returns first i in [l, r), p(i) false, and if none found, returns r
template <typename I, typename P>
I find_first_false(I l, I r, const P& p) {
    return bin_search_split<I, P, true>(l, r - 1, p);
}

// returns last i in [l, r), p(i) true, and if none found, returns l - 1
template <typename I, typename P>
I find_last_true(I l, I r, const P& p) {
    return bin_search_split<I, P, false>(l, r - 1, p);
}

template <bool rev>
vector<int> get_occ(string t, vector<string> s) {
    if constexpr (rev) {
        reverse(all(t));
        for (auto& x : s) reverse(all(x));
    }

    // res[i] = number of strings z in s such that z = t[i, ..., i + |z|)
    //          for not rev
    //
    // if rev is true then number of strings z in s such that z = t(i - |z|, ..., i]

    const int n = (int)s.size();

    string combined = t;
    combined += '$';
    rep(i, 0, n) combined += s[i] + '#';

    const int tot = (int)combined.size();
    const auto sa = atcoder::suffix_array(combined);
    const auto rnk = [&]() {
        vector<int> tmp(sa.size());
        int i = 0;
        for (auto x : sa) tmp[x] = i++;
        return tmp;
    }();
    const auto consec_lcp = atcoder::lcp_array(combined, sa);
    const auto st =
        rmq(tot - 1, [&](int i, int j) { return consec_lcp[i] < consec_lcp[j] ? i : j; });

    range_update_point_query<int> ds(tot);

    int ptr = sz(t) + 1;
    rep(string_num, 0, n) {
        const int i = rnk[ptr];
        const int len = sz(s[string_num]);
        {
            const auto j = find_first_false(
                i, tot - 1, [&](int j) { return consec_lcp[st.query(i, j + 1)] >= len; });
            ds.update(i, j + 1, +1);
        }
        {
            const auto j =
                find_last_true(0, i, [&](int j) { return consec_lcp[st.query(j, i)] < len; });
            ds.update(j + 1, i, +1);
        }
        ptr += len + 1;
    }
    assert(ptr == tot);

    ds.push_all();
    vector<int> res(t.size());
    rep(i, 0, sz(t)) res[i] = ds.leaf(rnk[i]);

    if constexpr (rev) reverse(all(res));
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t;
    cin >> t;

    int n;
    cin >> n;
    vector<string> s(n);
    for (auto& x : s) cin >> x;

    auto res_r = get_occ<false>(t, s), res_l = get_occ<true>(t, s);

    const int m = sz(t);
    assert(sz(res_l) == m && sz(res_r) == m);

    ll ans = 0;
    rep(i, 1, m) ans += (ll)res_l[i - 1] * res_r[i];
    cout << ans << '\n';
}
