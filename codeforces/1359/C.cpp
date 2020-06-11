#include <cmath>
#include <iostream>
using namespace std;

using ll = int64_t;
using ld = long double;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		ll c, h, t; cin >> h >> c >> t;
		if (2 * t <= c + h) {
			cout << 2 << '\n';
			continue;
		}
		auto f = [&](int k) -> ld {
			return ld(k * c + (k + 1) * h) / (2 * k + 1);
		};
		int l = 0, r = 2e9;
		while (l < r) {
			int m = l + (r - l) / 2;
			if (f(m) <= t) r = m;
			else l = m + 1;
		}
		cout << (abs(t - f(l)) < abs(f(l - 1) - t) ? 2ll * l + 1 : 2ll * l - 1) << '\n';
	}
}