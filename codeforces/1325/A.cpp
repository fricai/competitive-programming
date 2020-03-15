#include <iostream>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		int y = 1;
		while (x % 2 == 0) x /= 2, y *= 2;
		if (x == 1) cout << y / 2 << ' ' << y / 2 << '\n';
		else cout << y << ' ' << 1ll * y * (x - 1) << '\n';
	}
}