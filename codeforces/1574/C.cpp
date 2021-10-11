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

constexpr ll inf = 2e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<ll> a(n);
	for (auto &x : a)
		cin >> x;

	sort(all(a));

	ll s = accumulate(all(a), 0ll);

	int m; cin >> m;
	rep(e, 0, m) {
		ll x, y; cin >> x >> y;
		// minimize max(0, x - a[i]) + max(0, a[i] - s + y)
		
		ll ans = inf;
		/* 1. x - a[i] >= 0, a[i] - s + y > 0
		 *    x >= a[i] > s - y
		 *    x - s + y
		 */
		auto p = upper_bound(all(a), x);
		auto q = upper_bound(all(a), s - y);
		if (p > q)
			uin(ans, x - s + y);

		/* 2. x - a[i] >= 0, a[i] - s + y <= 0
		 * x >= a[i], s - y >= a[i]
		 * min(x, s - y) >= a[i]
		 *
		 * x - a[i], to minimize x - a[i], maximize a[i]
		 */

		auto it = x < s - y ? p : q;
		if (it != begin(a))
			uin(ans, x - *(it - 1));

		/* 3. x - a[i] < 0, a[i] - s + y > 0
		 * a[i] > x, a[i] > s - y
		 * a[i] > max(x, s - y)
		 * a[i] - s + y, minimize a[i] to get minimum
		 */

		auto notit = it != p ? p : q;
		if (notit != end(a))
			uin(ans, *notit - s + y);

		/* 4. x - a[i] < 0, a[i] - s + y <= 0
		 * x < a[i] <= s - y
		 * 0
		 */

		if (q > p)
			uin(ans, 0ll);

		cout << ans << '\n';
	}

}

