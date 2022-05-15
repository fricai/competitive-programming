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

void solve() {
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;

    vector<char> s(n * m);
    rep(i, 0, n * m) s[i] = str[i] - '0';
    // I spent > 45 mins debugging without realizing that i wrote
    // rep(i, 0, n)
    // instead of
    // rep(i, 0, n * m)

    vector<int> ans(n * m);

    {
        vector row(m, vector(n, 0));

        for (int i = 0; i < n * m; ++i)
            if (s[i]) ++row[0][i / m];

        for (int iter = 1; iter < m; ++iter) {
            rep(i, 0, n) row[iter][i] = row[iter - 1][i];
            for (int z = m - iter, k = 0; z < n * m; z += m, ++k) {
                if (!s[z]) continue;
                assert(k < n);
                --row[iter][k];
                if (k + 1 < n) ++row[iter][k + 1];
            }
        }

        vector sum(m, vector(n, 0));
        for (int x = 0; x < m; ++x) {
            sum[x][0] = row[m - 1 - x][0] > 0;
            for (int y = 1; y < n; ++y) sum[x][y] = sum[x][y - 1] + (row[m - 1 - x][y] > 0);
        }

        for (int x = 0; x < m; ++x)
            for (int y = 0; y < n; ++y) ans[m * y + x] = sum[x][y];
    }

    {
        vector<char> col(m);
        int cur = 0;
        rep(i, 0, n * m) {
            if (s[i] && !col[i % m]) {
                ++cur;
                col[i % m] = true;
            }
            ans[i] += cur;
        }
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
