#include <iostream>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

using ll = int64_t;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int h[n], ans[n]; rep(i, 0, n) cin >> h[i];
	ans[0] = 0;
	ans[1] = abs(h[1] - h[0]);
	rep(i, 2, n)
		ans[i] = min(ans[i - 1] + abs(h[i] - h[i - 1]),
			ans[i - 2] + abs(h[i] - h[i - 2]));
	cout << ans[n - 1];
}