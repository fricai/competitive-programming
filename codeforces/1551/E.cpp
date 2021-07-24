#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector dp(n + 1, vector(n + 1, -1));
	
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = 0;
		for (int j = 1; j <= n; ++j)
			if (dp[i - 1][j - 1] != -1) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
				if (a[i - 1] == j)
					uax(dp[i][j], dp[i - 1][j - 1] + 1);
			} else
				dp[i][j] = dp[i - 1][j];
	}

	int ans = -1;
	rep(i, 0, n + 1)
		if (dp[n][i] >= k)
			ans = i;
	if (ans < 0)
		return -1;
	return n - ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}