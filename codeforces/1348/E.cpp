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

const int N = 1 << 9;
const ll inf = 1e18;
bool dp[N][N];
int a[N], b[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k; ll tot = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		tot += a[i] + b[i];
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		rep(j, 0, k)
			rep(l, 0, min(k, a[i] + 1))
				if (a[i] % k == l || k <= (a[i] - l) % k + b[i])
					dp[i][j] |= dp[i - 1][(j - l + k) % k];

	ll ans = 0;
	rep(j, 0, k)
		if (dp[n][j])
			ckmax(ans, (tot - j) / k);
	cout << ans;
}