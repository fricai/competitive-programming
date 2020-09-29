#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 90, inf = 1e9;
int a[N];
int dp[N][N][N * N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];

	vector<int> x;
	for (int i = 0, j = 0; i <= n; i = ++j) {
		while (j < n && !a[j]) ++j;
		x.eb(j - i);
	}
	
	int z = sz(x);
	rep(i, 1, z) x[i] += x[i - 1];
	rep(i, 0, N)
		rep(j, 0, N)
			rep(s, 0, N * N) dp[i][j][s] = inf;
	
	dp[0][0][0] = 0;

	int t = n - z + 1;
	rep(i, 0, z)
		rep(j, 0, t + 1)
			rep(s, 0, n * (n - 1) / 2 + 1)
				if (dp[i][j][s] != inf)
					rep(k, j, t + 1)
						ckmin(dp[i + 1][k][s + abs(k - x[i])], dp[i][j][s] + (k - j) * (k - j));
	int mn = inf;
	rep(s, 0, n * (n - 1) / 2 + 1) {
		ckmin(mn, dp[z][t][s]);
		cout << (t * t - mn) / 2 << ' ';
	}
}