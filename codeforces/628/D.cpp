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

constexpr int mod = 1e9 + 7;
int add(int x, int y) { return x += y, x < mod ? x : x - mod; }
int sub(int x, int y) { return x -= y, x < 0 ? x + mod : x; }
void inc(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}
void dec(int& x, int y) {
    x -= y;
    if (x < 0) x += mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, d;
    cin >> m >> d;

    string a, b;
    cin >> a >> b;

    assert(sz(a) == sz(b));

    vector dp(sz(a), vector(m, array{-1, -1, -1, -1}));

    auto f = [&](const auto& g, int i, int val, bool tight_down, bool tight_up) -> int {
        if (i == sz(b)) return val == 0;

        auto& res = dp[i][val][tight_down << 1 | tight_up];
        if (res != -1) return res;
        res = 0;
        for (int nxt = 0; nxt < 10; ++nxt) {
            if ((i & 1) ^ (nxt == d)) continue;
            bool nxt_down = false, nxt_up = false;
            if (tight_down) {
                // matches with prefix of a
                if (nxt < a[i] - '0') continue;
                if (nxt == a[i] - '0') nxt_down = true;
            }
            if (tight_up) {
                if (nxt > b[i] - '0') continue;
                if (nxt == b[i] - '0') nxt_up = true;
            }
            inc(res, g(g, i + 1, (10 * val + nxt) % m, nxt_down, nxt_up));
        }
        return res;
    };
    cout << f(f, 0, 0, true, true) << '\n';
}
