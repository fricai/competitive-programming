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

const ll B = 10000;
const ll inf = B * (2e5 + 30);

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ld p, q, s; cin >> p >> q >> s;
	ll a = round(B * p);
	ll b = round(B * q);
	ll r = round(B * s);

	ll ans = 0;
	for (ll x = -inf; x <= inf; x += B) {
		ll d = r * r - (x - a) * (x - a);
		if (d < 0) continue;
		ll l = 0, r = sqrt(d) + 30;
		while (r - l > 1) {
			ll m = l + (r - l) / 2;
			(m * m <= d ? l : r)  = m;
		}
		
		ans += (b + l + inf) / B - (b - r + inf) / B;
	}

	cout << ans;
}