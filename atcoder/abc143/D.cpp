#include <algorithm>
#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int l[n]; REP(i, 0, n) cin >> l[i];
	sort(l, l + n);
	int ans = 0;
	REP(i, 0, n)
		REP(j, i + 1, n)
			ans += lower_bound(l, l + n, l[i] + l[j]) - l - j - 1;
	cout << ans;
}