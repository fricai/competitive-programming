#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int d[n]; REP(i, 0, n) cin >> d[i];
	long long ans = 0;
	REP(i, 0, n)
		REP(j, i + 1, n)
			ans += d[i] * d[j];
	cout << ans;
}