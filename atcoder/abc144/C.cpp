#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n; cin >> n;
	ll ans = n + 1;
	for (ll i = 1; i * i <= n; ++i)
		if (n % i == 0)
			ans = min(ans, i + n / i - 2);
	cout << ans;
}