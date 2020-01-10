#include <algorithm>
#include <iostream>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = long long;

signed main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	ll x; cin >> x;
	ll z = x, y = 1;
	for (ll d = 1; d * d <= x; ++d) {
		if (x % d == 0) {
			if (__gcd(d, x / d) == 1) {
				if (x / d < z) {
					z = x / d;
					y = d;
				}
			}
		}
	}
	cout << y << ' ' << z;
}