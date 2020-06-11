#include <iostream>
using namespace std;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		cout << (m <= n / k ? m : n / k - (m - n / k + k - 2) / (k - 1)) << '\n';
	}
}