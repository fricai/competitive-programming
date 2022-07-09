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

constexpr ll inf = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector g(n, vector(n, inf));
    rep(e, 0, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        uin(g[u][v], w);
    }

    vector<ll> d;
    vector<bool> chosen;
    rep(s, 0, n) {
        chosen.assign(n, false);

        d = g[s];
        // to make sure that first transition isn't v -> (v + 1) % n
        // note that d[s] != 0

        rep(iteration, 0, n) {
            int u = -1;
            rep(j, 0, n) if (!chosen[j] && (u == -1 || d[j] < d[u])) u = j;
            assert(u != -1 && d[u] < inf);
            chosen[u] = true;

            // for an edge u -> v,
            // u -> wait for t -> (v + t) % n
            //
            // is the same as
            //
            // u -> v -> (v + 1) % n -> (v + 2) % n -> .. (v + t) % n

            uin(d[(u + 1) % n], d[u] + 1);
            rep(v, 0, n) uin(d[(v + d[u]) % n], d[u] + g[u][v]);
        }

        d[s] = 0;
        rep(v, 0, n) cout << d[v] << ' ';
        cout << '\n';
    }
}
