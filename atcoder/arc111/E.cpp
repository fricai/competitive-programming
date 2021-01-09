#include <bits/stdc++.h>
#include <atcoder/math>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using namespace atcoder;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        ll n = (d - 2) / (c - b);
        ll ans = n;
        ans -= floor_sum(n + 1, d, c, a) - a / d;
        ans += floor_sum(n + 1, d, b, a - 1) - (a - 1) / d;
        cout << ans << '\n';
    }
}