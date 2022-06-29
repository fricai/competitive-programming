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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<bool> v;
    {
        string s;
        cin >> s;
        n = s.size();
        v.assign(n + 1, false);
        rep(i, 0, n) v[i + 1] = s[i] == '1';
    }
    if (v != vector(rall(v)) || !v[1]) return cout << "-1\n", 0;

    vector<pair<int, int>> edges;
    auto add_edge = [&](int x, int y) { edges.emplace_back(x + 1, y + 1); };

    vector<int> pos;
    for (int i = 1; i <= n; ++i)
        if (v[i]) pos.push_back(i);

    rep(i, 0, sz(pos)) add_edge(i, i + 1);
    for (int i = 1, cur = sz(pos); i < sz(pos); ++i)
        for (int j = 0; j < pos[i] - pos[i - 1] - 1; ++j) add_edge(i, ++cur);

    assert(sz(edges) == n - 1);
    for (auto [x, y] : edges) cout << x << ' ' << y << '\n';
}
