#include <iostream>
using namespace std;
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x, y; cin >> n >> x >> y;
	long long a[n]; REP(i, 0, n) cin >> a[i];
	REP(d, 0, n) {
		bool flag = 1;
		REP(j, max(0, d - x), d) if (a[j] <= a[d]) flag = 0;
		REP(j, d + 1, min(n, d + y + 1)) if (a[j] <= a[d]) flag = 0;
		if (flag) {
			cout << d + 1 << '\n';
			break;
		}
	}
}