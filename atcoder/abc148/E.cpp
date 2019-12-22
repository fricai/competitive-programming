#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;

ll v(ll p, ll n) { // return v_p(n!)
	ll a = p;
	ll res = 0;
	ll x = 1;
	while (a <= n) {
		res += n / a;
		a *= p;
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n; cin >> n;
	if (n & 1LL) cout << 0;
	else {
		cout << v(5, n / 2);
	}
}