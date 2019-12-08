#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n; ll a[n];
	REP(i, 0, n) cin >> a[i];
	ll ans = 0, p = 1;
	REP(i, 0LL, 61) {
		ll zc = 0, oc = 0, s = 0;
		REP(j, 0LL, n) { 
			if (a[j] & 1LL) oc++; 
			else zc++;
			a[j] >>= 1LL;
		}
		s = (1LL << i) % mod;
		s = oc * s % mod;
		s = zc * s % mod;
		ans = (ans + s) % mod;
	}
	cout << ans;
}