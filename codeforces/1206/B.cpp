#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	int n; cin >> n;

	int a[n];
	REP(i, 0, n) cin >> a[i];
	int neg = 0;
	long long ans = 0;
	bool zero = 0;
	REP(i, 0, n) {
		if (a[i] < 0) {
			ans += - 1 - a[i];
			++neg;
		}
		if (a[i] > 0)
			ans += a[i] - 1;
		if (a[i] == 0) {
			++ans;
			zero = 1;
		}
	}
	if (neg % 2 == 0 || zero) cout << ans;
	else cout << ans + 2LL;
}