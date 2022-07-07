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

void next_move(vector<int> v) {
    assert(!v.empty());
    cout << "next";
    for (auto x : v) cout << ' ' << x;
    cout << endl;
}

auto get_groups() {
    int k;
    cin >> k;
    vector<vector<int>> v(k);
    for (auto& t : v) {
        string s;
        cin >> s;
        for (auto c : s) t.push_back(c - '0');
    }
    return v;
}

void done() { cout << "done" << endl; }

signed main() {
    ios::sync_with_stdio(false);

    vector<vector<int>> cur;
    assert(cur.empty());
    while (sz(cur) != 2) {
        next_move({0, 1});
        cur = get_groups();
        next_move({1});
        cur = get_groups();
    }
    assert(sz(cur) == 2);
    assert(cur[0] == vector({0, 1}) || cur[1] == vector({0, 1}));

    while (sz(cur) != 1) {
        next_move({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        cur = get_groups();
    }
    assert(sz(cur) == 1);

    done();
}
