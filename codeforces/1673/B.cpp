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

constexpr int A = 26;

int dist(const string& s) {
    bool f[A] = {};
    for (auto c : s) f[c - 'a'] = true;
    return count(all(f), true);
}

bool solve() {
    string s;
    cin >> s;
    const int cnt = dist(s);
    rep(i, 0, sz(s) - cnt + 1) if (dist(s.substr(i, cnt)) != cnt) return false;
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}
