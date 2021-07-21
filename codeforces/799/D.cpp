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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a, b, h, w, n;
	cin >> a >> b >> h >> w >> n;

	if ((a <= h && b <= w) || (a <= w && b <= h))
		return cout << "0\n", 0;
	
	vector<ll> z(n);
	for (auto &x : z) cin >> x;
	sort(rall(z));
	uin(n, 34);
	z.resize(n);
	
	ll U = max({a, b, w, h});
	vector dp(n + 1, vector(U + 1, 0ll));
	dp[0][w] = h;
	
	rep(i, 0, n) {
		for (int x = 1; x <= U; ++x)
			dp[i + 1][x] = dp[i][x];
		for (int x = 1; x <= U; ++x) {
			uax(dp[i + 1][x], min(U, dp[i][x] * z[i]));
			uax(dp[i + 1][min(U, x * z[i])], dp[i][x]);
		}
		
		for (int x = 1; x <= U; ++x)
			if ((b <= x && a <= dp[i + 1][x])
				|| (a <= x && b <= dp[i + 1][x]))
				return cout << i + 1 << '\n', 0;
	}
	cout << "-1\n";
}