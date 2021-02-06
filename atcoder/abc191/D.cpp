#include <bits/stdc++.h>

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

const int inf = 2e5 + 30;
const ll mult = 10000;

ll count_multiples(ll a, ll b, ll c) {
    if (b < a) return 0;
    if (c < 0) c = -c;
    long al = a, bl = b, cl = c;
    if (c == 1) return bl - al + 1;
    return ((bl + (b < 0 ? 1 : 0)) / cl) -
           ((al - (a > 0 ? 1 : 0)) / cl) +
           ((a <= 0 && b >= 0) ? 1 : 0);
}

bool f(ll d, ll x) {
	return d * d <= x;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ld p, q, s; cin >> p >> q >> s;
	ll a = round(mult * p);
	ll b = round(mult * q);
	ll r = round(mult * s);

	ll ans = 0;
	for (ll x = -mult * inf; x <= mult * inf; x += mult) {
		ll d = r * r - (x - a) * (x - a);
		if (d < 0) continue;
		ll l = 0, r = sqrt(d) + 30;
		while (r - l > 1) {
			ll m = l + (r - l) / 2;
			(f(m, d) ? l : r)  = m;
		}

		// ll down = ceil(sqrt(d));
		// assert(up * up <= d && d < (up + 1) * (up + 1));
		// assert(down * down >= d && d > (down - 1) * (down - 1));
		ll L = b - l;
		ll R = b + l;
		ans += count_multiples(L, R, mult);
	}

	cout << ans;
}