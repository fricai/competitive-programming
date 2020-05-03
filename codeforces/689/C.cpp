#include <iostream>
using namespace std;

using ll = long long;

ll f(ll n) {
	return 1ll * n * n * n;
}

ll sum(ll n) {
	ll s = 0;
	for (ll k = 2; f(k) <= n; ++k)
		s += n / f(k);
	return s;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll m, l = 1, r = 1e18; cin >> m;
	while (l < r) {
		ll mid = l + (r - l) / 2;
		if (m <= sum(mid)) r = mid;
		else l = mid + 1;
	}
	cout << (sum(l) == m ? l : -1);
}