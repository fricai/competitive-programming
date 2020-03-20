#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)
#define ff first
#define ss second

using ll = int64_t;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

constexpr ll inf = 2e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int a[n]; rep(i, 0, n) cin >> a[i];
	auto sum = [&](int l, int r) {
		ll s = 0;
		for (int i = l; i <= r; ++i) s += a[i];
		return s;
	};
	ll dp[n][n];
	per(l, 0, n) {
		dp[l][l] = 0;
		rep(r, l + 1, n) {
			dp[l][r] = inf;
			rep(m, l, r) ckmin(dp[l][r], dp[l][m] + dp[m + 1][r]);
			dp[l][r] += sum(l, r);
		}
	}
	cout << dp[0][n - 1];
}