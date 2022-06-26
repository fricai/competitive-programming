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

int ask(int u, int v) {
    assert(u + v > 1);
    cout << "? " << u + 1 << ' ' << v + 1 << endl;
    int x;
    cin >> x;
    assert(x != -1);
    return x;
}

void answer(int x) { cout << "! " << x << endl; }

signed main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int dist = n;
    vector<int> lst;
    rep(i, 2, n) {
        const auto cur = ask(0, i) + ask(1, i);
        uin(dist, cur);
        if (cur == 3) lst.push_back(i);
    }
    if (dist == 3) {
        if (sz(lst) != 2)
            dist = 1;
        else {
            const auto x = lst[0];
            const auto y = lst[1];
            const auto dxy = ask(x, y);
            assert(dxy == 1 || dxy == 2 || dxy == 3);
            if (dxy != 1) dist = 1;
        }
    }
    answer(dist);
}
