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

const int N = 1 << 7;
int ord[N], a[N], c[N];
int dp[2][N][10010];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int n; cin >> n;
	int A = 0;
	rep(i, 0, n) cin >> c[i] >> a[i], A += a[i], ord[i] = i;
	// sort(ord, ord + n, [&](int x, int y) { return 2 * c[x] - a[x] > 2 * c[y] - a[y]; });
	for (int i = 1, cur = 1, pre = 0; i <= n; ++i, cur ^= 1, pre ^= 1) {
		for (int k = 1; k <= n; ++k) {
			for (int X = 0; X <= A; ++X) {
				dp[cur][k][X] = dp[pre][k][X];
				if (X >= 2 * c[i - 1] - a[i - 1]) {
					ckmax(dp[cur][k][X], 2 * c[i - 1] + dp[pre][k - 1][X - 2 * c[i - 1] + a[i - 1]]);
				} else ckmax(dp[cur][k][X], a[i - 1] + X + dp[pre][k - 1][0]);
			}
		}
	}

	cout << fixed << setprecision(10);
	for (int j = 1; j <= n; ++j) cout << ((double)dp[n % 2][j][A]) / 2 << ' ';
}