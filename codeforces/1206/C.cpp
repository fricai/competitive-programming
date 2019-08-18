#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	int n; cin >> n;
	if (n & 1) {
		int a[2 * n + 1];
		REP(i, 1, n + 1) {
			if (i & 1) {
				a[i] = i;
				a[i + n] = i + 1;
			}
			else {
				a[i] = 2 * n - i + 2;
				a[i + n] = 2 * n - i + 1;
			}
		}

		cout << "YES\n";
		REP(i, 1, 2 * n + 1) cout << a[i] << ' ';
	} else cout << "NO";
}