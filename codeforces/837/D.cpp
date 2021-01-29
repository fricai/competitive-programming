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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 8, Z = 30, inf = 1e9;
ll a[N];
int v2[N], v5[N];
int dp[2][N][Z * N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		while (a[i] % 2 == 0) a[i] /= 2, ++v2[i];
		while (a[i] % 5 == 0) a[i] /= 5, ++v5[i];
	}

	// let dp[i][j][l] be the maximum number of sum of v2 you can get by choosing 
	// j elements from first i elements and sum of v5 is l
	// j = 0 and l is neq 0 should be impossible

	for (int j = 0; j <= n; ++j)
		for (int l = 0; l < Z * N; ++l)
			dp[0][j][l] = -inf;
	
	dp[0][0][0] = 0;
	
	for (int i = 1, cur = 1, pre = 0; i <= n; ++i, cur ^= 1, pre ^= 1) {	
		dp[cur][0][0] = 0;
		for (int l = 1; l < Z * N; ++l) dp[cur][0][l] = -inf;

		for (int j = 1; j <= n; ++j) {
			for (int l = 0; l < v5[i]; ++l)
				dp[cur][j][l] = dp[pre][j][l];
				
			for (int l = v5[i]; l < Z * N; ++l)
				dp[cur][j][l] = max(dp[pre][j][l], dp[pre][j - 1][l - v5[i]] + v2[i]);
		}
	}

	int mx = 0;
	rep(l, 0, Z * N) ckmax(mx, min(l, dp[n & 1][k][l]));
	cout << mx;
}