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

const int N = 1 << 19, X = 1 << 21;
int a[N];
ll f[X], s[X];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; ll x, y; cin >> n >> x >> y;
	rep(i, 0, n) cin >> a[i];

	int g = 0;
	rep(i, 0, n) g = gcd(g, a[i]);
	if (g > 1) return cout << 0, 0;

	rep(i, 0, n) ++f[a[i]], s[a[i]] += a[i];
	rep(i, 1, X) f[i] += f[i - 1], s[i] += s[i - 1];
	
	ll ans = 1e18;
	int z = (x + y) / y;
	for (int g = 2; g < X; ++g) {
		int r = min(g, z);
		ll cur = 0;
		for (int d = g; d < X; d += g) {
			// for elements c in range (d - g, d], min(x, y * (d - c))
			// x < y * (d - c) <=>  c < d - floor(x/y)
			// so for (d - g, d - floor(x / y)] -> x = cnt(d - g, d - r) * x
			// for (d - floor(x / y), d] -> y * (d - c) = cnt(d - r, d) * y * d - sum(d - r, d)
			// rep(i, 0, n) {
			// 	if (d - g < a[i] && a[i] <= d - r) cur += x;
			// 	if (d - r < a[i] && a[i] <= d) cur += y * (d - a[i]);
			// }
			// assert(d - r >= 0 && d - g >= 0);
			// x < y * (d - c) <=> x/y < d - c <=> c < d - floor(x / y)
			// d - g < c <= d - floor(x / y) - 1
			// x <= y * (d - c) <=> 
			cur += (f[d - r] - f[d - g]) * x;
			cur += ((f[d] - f[d - r]) * d - (s[d] - s[d - r])) * y;
		}
		ckmin(ans, cur);
		// if (ckmin(ans, cur)) cerr << g << '\n';
	}
	cout << ans << '\n';

}