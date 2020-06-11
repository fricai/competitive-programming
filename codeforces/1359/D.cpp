#include <iostream>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

const int inf = 1e9;
int a[1 << 17];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];

	int ans = 0;
	rep(mx, 0, 31) {
		int cur = 0, tot = 0;
		rep(i, 0, n) {
			cur += (a[i] > mx ? -inf : a[i]);
			if (cur < 0) cur = 0;
			else if (tot < cur)
				tot = cur;
		}
		ans = max(ans, tot - mx);
	}
	cout << ans;
}