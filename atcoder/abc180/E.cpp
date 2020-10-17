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

const int N = 18;
const ll inf = 1e18;

ll dp[N][1 << N];
int x[N], y[N], z[N];

int dist(int i, int j) { // a -> b
	return abs(x[j] - x[i]) + abs(y[j] - y[i]) + max(0, z[j] - z[i]);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) rep(S, 0, 1 << n) dp[i][S] = inf;

	rep(i, 0, n) cin >> x[i] >> y[i] >> z[i];

	dp[0][1] = 0;
	rep(S, 2, 1 << n)
		rep(i, 0, n)
			if (S >> i & 1)
				rep(j, 0, n)
					if (S >> j & 1)
						ckmin(dp[i][S], dist(j, i) + dp[j][S ^ (1 << i)]);
	ll ans = inf;
	rep(j, 1, n) ckmin(ans, dist(j, 0) + dp[j][(1 << n) - 1]);
	cout << ans;
}