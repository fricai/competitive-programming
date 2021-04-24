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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	vector<vector<pair<int, int>>> constraint(n); 
	rep(i, 0, m) {
		int x, y, z; cin >> x >> y >> z;
		constraint[--x].emplace_back(y, z);
	}

	vector<ll> dp(1 << n);
	dp[0] = 1;
	rep(S, 0, 1 << n) {
		int x = __builtin_popcount(S);
		rep(i, 0, n) {
			if (S >> i & 1) continue;

			int T = S | 1 << i;
			bool valid = 1;
			for (auto [y, z] : constraint[x])
				valid &= __builtin_popcount(T & ((1 << y) - 1)) <= z;
			if (valid) dp[T] += dp[S];
		}
	}

	cout << dp.back() << '\n';
}