#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	int n; cin >> n;
	int a[n];
	REP(i, 0, n) cin >> a[i];
	int m; cin >> m;
	int b[m];
	REP(i, 0, m) cin >> b[i];

	REP(i, 0, n) {
		REP(j, 0, m) {
			int x = a[i] + b[j];
			bool flag = 1;
			REP(o, 0, m) if (b[o] == x) flag = 0;
			REP(p, 0, n) if (a[p] == x) flag = 0;
			if (flag) {
				cout << a[i] << ' ' << b[j];
				return 0;
			}
		}
	}
}