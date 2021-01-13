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

const int N = 1 << 6;
ll dp[2][N][N * N];
int a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x; cin >> n >> x;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int s = 0; s <= n * N; ++s)
				dp[i & 1][j][s] = dp[~i & 1][j][s];
			if (j)
			for (int s = a[i]; s <= n * N; ++s)
				dp[i & 1][j][s] += dp[~i & 1][j - 1][s - a[i]];
		}
	}

	ll ans = 0;	
	for (int j = 1; j <= n; ++j) {
		for (int s = 1; s <= n * N; ++s) {
			if (s == x * j) ans += dp[n & 1][j][s];
		}
	}
	cout << ans;
}