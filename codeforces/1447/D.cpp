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

const int N = 5005;
int dp[N][N];
char s[N], t[N];

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
 
	int n, m; cin >> n >> m;
	cin >> (s + 1) >> (t + 1);

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i] == t[j]) dp[i][j] = 2 + max(0, dp[i - 1][j - 1]);
			else dp[i][j] = max({0, dp[i - 1][j], dp[i][j - 1]}) - 1;
			ckmax(ans, dp[i][j]);
		}
	}
	cout << ans;
}