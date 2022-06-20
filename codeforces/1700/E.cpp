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

    int n, m;
    cin >> n >> m;

    vector a(n, vector(m, 0));
    for (auto& x : a)
        for (auto& y : x) cin >> y;

    constexpr array<pair<int, int>, 4> dir = {pair(0, +1), pair(0, -1), pair(+1, 0), pair(-1, 0)};
    auto valid = [n, m](int i, int j) { return 0 <= i && i < n && 0 <= j && j < m; };

    vector connected(n, vector<bool>(m));
    int conn_cnt = 0;
    auto update = [&](int x, int y) {
        assert(valid(x, y));
        conn_cnt -= connected[x][y];
        connected[x][y] = false;

        if (a[x][y] == 1) {
            connected[x][y] = true;
            ++conn_cnt;
            return;
        }

        for (auto [dx, dy] : dir)
            if (valid(x + dx, y + dy)) {
                if (a[x][y] > a[x + dx][y + dy]) {
                    connected[x][y] = true;
                    ++conn_cnt;
                    return;
                }
            }
    };

    rep(i, 0, n) rep(j, 0, m) update(i, j);

    if (conn_cnt == n * m) return cout << "0\n", 0;

    auto do_swap = [&](int x, int y, int i, int j) {
        swap(a[x][y], a[i][j]);
        update(x, y);
        update(i, j);
        for (auto [dx, dy] : dir) {
            if (valid(x + dx, y + dy)) update(x + dx, y + dy);
            if (valid(i + dx, j + dy)) update(i + dx, j + dy);
        }
    };

    int ptx = -1, pty = -1;
    {
        int mn = n * m + 1;
        rep(i, 0, n) rep(j, 0, m) if (!connected[i][j] && uin(mn, a[i][j])) ptx = i, pty = j;
    }
    assert(ptx >= 0 && pty >= 0);

    vector<pair<pair<int, int>, pair<int, int>>> res;
    auto test = [&](int x, int y) {
        const auto one = pair(x, y);
        rep(i, 0, n) rep(j, 0, m) {
            do_swap(x, y, i, j);
            if (conn_cnt == n * m) {
                const auto two = pair(i, j);
                if (one < two)
                    res.emplace_back(one, two);
                else
                    res.emplace_back(two, one);
            }
            do_swap(x, y, i, j);
        }
    };

    test(ptx, pty);
    for (auto [dx, dy] : dir) {
        const auto nx = ptx + dx, ny = pty + dy;
        if (valid(nx, ny)) test(nx, ny);
    }

    sort(all(res));
    res.erase(unique(all(res)), end(res));

    /*
    for (auto [p, q] : res)
        cerr << p.first << ' ' << p.second << "  " << q.first << ' ' << q.second << '\n';
    */

    if (res.empty())
        cout << "2\n";
    else
        cout << "1 " << sz(res) << '\n';
}
