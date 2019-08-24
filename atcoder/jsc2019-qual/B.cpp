#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const long long mod = 1e9 + 7, inv2 = 500000004;

signed main() {
	long long n, k; cin >> n >> k;
	int a[n];
	REP(i, 0, n) cin >> a[i];
	long long ans = 0;

	REP(i, 0, n) {
		long long x = 0, y = 0;
		REP(j, 0, i) y += (a[i] > a[j]);
		REP(j, i + 1, n) x += (a[i] > a[j]);
		ans += (k * x) % mod + (((k * (k - 1) % mod) * inv2 % mod) * (x + y) % mod);
		ans %= mod;
	}
	cout << ans;
}