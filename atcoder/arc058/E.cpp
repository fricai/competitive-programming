#include <bits/stdc++.h>
#include <atcoder/modint>

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


using Int = atcoder::static_modint<1000000007>;
Int dp[42][1 << 18];
// dp[n][S] = number of subsequences which end with a suffix with sum x in S
// where we never encounter a suffix where target is subset of S

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x, y, z; cin >> n >> x >> y >> z;
	int target = 1 << z | 1 << (y + z) | 1 << (x + y + z);
	int U = (1 << (x + y + z + 1)) - 1;
	dp[0][1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int S = 0; S <= U; ++S) {
			for (int a = 1; a <= 10; ++a) {
				int T = (S << a | 1) & U;
				if ((target & T) != target) dp[i][T] += dp[i - 1][S];
			}
		}
	}

	Int ans = 1;
	for (int i = 1; i <= n; ++i) ans *= 10;
	for (int S = 0; S <= U; ++S) ans -= dp[n][S];
	cout << ans.val();
}