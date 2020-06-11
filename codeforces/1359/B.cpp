#include <iostream>
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n, m, x, y; cin >> n >> m >> x >> y;
		y = min(y, 2 * x);
		int cx = 0, cy = 0;
		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			for (int j = 0; j < m; ++j) {
				int prev = j;
				while (j < m && s[j] == '.') ++j;
				cx += (j - prev) % 2;
				cy += (j - prev) / 2;
			}
		}
		cout << cx * x + cy * y << '\n';
	}
}