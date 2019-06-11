#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q;
	while(q--) {
		long long n; cin >> n;
		long long ans = 0;
		while (n > 1) {
			if (n % 2 == 0) n = n / 2;
			else if (n % 3 == 0) n = 2 * n / 3;
			else if (n % 5 == 0) n = 4 * n / 5;
			else ans = -2, n = 1;
			++ans;
		}
		cout << ans << '\n';
	}
}
