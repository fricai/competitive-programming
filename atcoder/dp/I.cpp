#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)

using ll = int64_t;
using ld = long double;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

constexpr ll inf = 2e18;
constexpr int M = 1e9 + 7;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	ld p[n]; rep(i, 0, n) cin >> p[i];
	ld dp[n + 1];
	rep(i, 0, n + 1) rep(x, 0, n + 1) dp[x] = 0;
	dp[0] = 1;
	rep(i, 0, n) {
		per(x, 0, n)
			dp[x + 1] = p[i] * dp[x] + (1 - p[i]) * dp[x + 1];
		dp[0] = (1 - p[i]) * dp[0];
	}
	ld ans = 0;
	rep(x, n / 2, n) ans += dp[x + 1];
	cout << fixed << setprecision(10) << ans;
}