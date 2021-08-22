#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M = 119 << 23 | 1;

ll g(ll r, bool parity) {
	// number of elements in [0, r] with given parity
	// x = parity mod 2
	// x - parity = 0 mod 2
	// 0 <= x <= r
	return (r + parity) / 2;
}

ll f(ll l, ll r, bool parity) {
	if (l > r)
		return 0;
	return g(r, parity) - g(l - 1, parity);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n; cin >> n;

	/*
	 * x^2 - y = z^2 => (x - z)(x + z) = y
	 * => a = x - z, b = x + z
	 * => 1 <= (a + b) / 2 <= n
	 * 	a = b mod 2
	 * 1 <= ab <= n
	 * 1 <= a^2 <= ab <= n
	 */

	ll ans = 0;
	for (ll a = 1; a * a <= n; ++a)
		(ans += f(a, min(n / a, 2 * n - a), a & 1)) %= M; 

	cout << ans << '\n';
}
