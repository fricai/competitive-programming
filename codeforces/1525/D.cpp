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

const int N = 5e3 + 5, inf = 1e9;
int dp[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	rep(i, 0, n + 1) rep(j, 0, n + 1) dp[i][j] = inf;
	dp[0][0] = 0;

	vector<int> taken;
	rep(i, 0, n) if (a[i]) taken.push_back(i);
	int m = sz(taken);
	
	rep(i, 0, n) {
		for (int j = 0; j <= m; ++j)
			uin(dp[i + 1][j], dp[i][j]);
		
		if (a[i]) continue;
		for (int j = 0; j < m; ++j)
			uin(dp[i + 1][j + 1], dp[i][j] + abs(i - taken[j]));
	}
	
	cout << dp[n][m] << '\n';
}