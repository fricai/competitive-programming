#include <iostream>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

using ll = int64_t;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll inf = 2e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	ll h[n], ans[n]; rep(i, 0, n) cin >> h[i];
	ans[0] = 0;
	rep(i, 1, n) {
		ans[i] = inf;
		rep(j, max(0, i - k), i)
				ckmin(ans[i], ans[j] + abs(h[i] - h[j]));
	}
	cout << ans[n - 1];
}