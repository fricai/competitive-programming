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

constexpr int N = 100032, inf = 2e9 + 10;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector a(n, pair(0, vector<int>(m)));
    vector<int> cmp;
    for (auto& [w, v] : a) {
        for (auto& x : v) cin >> x;
        cin >> w;
        cmp.insert(end(cmp), all(v));
    }
    sort(all(cmp));
    cmp.erase(unique(all(cmp)), end(cmp));

    const int r = sz(cmp);

    for (auto& [w, v] : a)
        for (auto& x : v) x = lower_bound(all(cmp), x) - begin(cmp);
    cmp.clear();
    cmp.shrink_to_fit();

    sort(all(a));

    vector<vector<int>> pos(r);
    rep(i, 0, n) for (auto x : a[i].second) pos[x].push_back(i);

    vector<bitset<N>*> blocked(r, nullptr);
    constexpr int B = N / 128;
    rep(i, 0, r) if (sz(pos[i]) > B) {
        blocked[i] = new bitset<N>();
        for (auto x : pos[i]) blocked[i]->set(x);
    }

    int ans = inf;
    rep(i, 0, n) {
        const auto& [w, v] = a[i];
        bitset<N> cur_blocked;
        for (auto x : v)
            if (blocked[x] != nullptr)
                cur_blocked |= *blocked[x];
            else
                for (auto j : pos[x]) cur_blocked.set(j);

        const int j = (~cur_blocked)._Find_first();
        if (j < i) uin(ans, w + a[j].first);

        for (auto x : v)
            if (blocked[x] != nullptr) blocked[x]->set(i);
    }
    cout << (ans < inf ? ans : -1) << '\n';
}
