#include <iostream>
using namespace std;

const int inf = 1e9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	cout << "YES\n";
	while (n--) {
		int x, y, _; cin >> x >> y >> _ >> _;
		x += inf; y += inf;
		cout << ((x & 1) << 1 | y & 1) + 1 << '\n';
	}
}