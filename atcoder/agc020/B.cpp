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

const int K = 1 << 17;
int a[K];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k; cin >> k;
	per(i, 0, k) cin >> a[i];

	ll l = 2, r = 2;
	rep(i, 0, k) {
		// smallest divisor of a[i] in [l, r]
		ll x = (l + a[i] - 1) / a[i] * a[i];

		// greatest divisor of a[i] in [l, r]
		ll y = r / a[i] * a[i];
		if (r < x) return cout << -1, 0;
		assert(l <= y);

		l = x;
		r = y + a[i] - 1;
	}
	cout << l << ' ' << r << '\n';
}