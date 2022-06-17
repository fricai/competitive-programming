#include <algorithm>
#include <iostream>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)

using ll = int64_t;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll inf = 2e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, w; cin >> n >> w;
	ll v[n], c[n], dp[w + 1];
	rep(i, 0, n) cin >> c[i] >> v[i];
	rep(x, 0, w + 1) dp[x] = 0;
	rep(i, 0, n)
		per(x, c[i], w + 1)
				ckmax(dp[x], dp[x - c[i]] + v[i]);
	cout << dp[w];
}