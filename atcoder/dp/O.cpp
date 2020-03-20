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

const int M = 1e9 + 7;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int B = 21;
int dp[1 << B];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int a[n][n]; rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
	dp[(1 << n) - 1] = 1;
	per(S, 0, 1 << n) {
		int i = __builtin_popcount(S);
		rep(j, 0, n)
			if ((~S & 1 << j) && a[i][j])
				(dp[S] += dp[S | 1 << j]) %= M;
	}
	cout << dp[0];
}