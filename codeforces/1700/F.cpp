#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a);)
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
    cin >> n;

    array<vector<int>, 2> a, b;
    int del = 0;
    for (auto& v : a) {
        v = vector<int>(n);
        for (auto& x : v) cin >> x, del += x;
    }
    for (auto& v : b) {
        v = vector<int>(n);
        for (auto& x : v) cin >> x, del -= x;
    }
    if (del != 0) return cout << "-1\n", 0;

    array<queue<int>, 2> qa, qb;
    ll ans = 0;
    rep(i, 0, n) {
        for (auto j : {0, 1}) {
            if (a[j][i]) qa[j].push(i);
            if (b[j][i]) qb[j].push(i);
        }
        for (auto j : {0, 1}) {
            while (!qa[j].empty() && !qb[j].empty()) {
                const auto del = abs(qa[j].front() - qb[j].front());
                ans += del;
                qa[j].pop();
                qb[j].pop();
            }
        }
        for (auto j : {0, 1}) {
            while (!qa[j].empty() && !qb[!j].empty()) {
                const auto del = abs(qa[j].front() - qb[!j].front());
                ans += del + 1;
                qa[j].pop();
                qb[!j].pop();
            }
        }
    }
    cout << ans << '\n';
}
