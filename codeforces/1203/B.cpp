#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q;
	while(q--) {
		int n; cin >> n;
		int x[(int) 1e4], a[4 * n];
		REP(i, 0, 1e4) x[i] = 0;
		REP(i, 0, 4 * n) {
			cin >> a[i];
			++x[a[i] - 1];
		}
		sort(a, a + 4 * n);
		bool flag = 1;
		REP(i, 0, 1e4)
			if (x[i] & 1)
				flag = 0;

		int z = a[0] * a[4 * n - 1];

		REP(i, 0, 1e4)
			if (x[i] > 0)
				if (z % (i + 1) != 0 || x[z/(i + 1) - 1] != x[i])
					flag = 0;

		cout << (flag ? "YES" : "NO") << '\n';
	}
}