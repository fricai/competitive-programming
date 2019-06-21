#include <iostream>
using namespace std;

signed main() {
	int n; cin >> n; int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i]; a[i] = - a[i] - 1;
		if (a[i] >= 0) a[i] = -(a[i] + 1);
	}
	if (n & 1) {
		int m = -a[0], idx = 0;
		for (int i = 0; i < n; ++i) {
			if (-a[i] > m) {
				m = -a[i];
				idx = i;
			}
		}
		a[idx] = -(a[idx] + 1);
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
}
