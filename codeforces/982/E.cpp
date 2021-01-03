#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	if ((a - b) % g != 0) return -1;
	// assert((a - b) % g == 0); // else no solution
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m * n / g : x;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m, x, y, vx, vy;
	cin >> n >> m >> x >> y >> vx >> vy;

	if (vx && vy) {
		ll a = crt(((-vx * x) % n + n) % n, n, ((-vy * y) % m + m) % m, m);
		if (a < 0) cout << -1;
		else {
			assert(0 <= a && a < n * m / gcd(n, m));
			ll cn = x + a * vx;
			ll dm = y + a * vy;
			assert(cn % n == 0);
			assert(dm % m == 0);
			cout << abs(cn / n % 2) * n << ' ' << abs(dm / m % 2) * m;
		}
	} else if (vx) {
		if (y == 0 || y == m) cout << (vx > 0 ? n : 0) << ' ' << y;
		else cout << -1;
	} else if (vy) {
		if (x == 0 || x == n) cout << x << ' ' << (vy > 0 ? m : 0);
		else cout << -1;
	} else cout << -1;
}