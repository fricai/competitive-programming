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

const int M = 119 << 23 | 1;
int add(int x, int y) { return x += y, x < M ? x : x - M; }
int sub(int x, int y) { return x -= y, x < 0 ? x + M : x; }
void inc(int &x, int y) { x += y; if (M <= x) x -= M; }
int mul(ll x, int y) { return x * y % M; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> v(n, 0);
		
	for (auto &x : v) {
		char c; cin >> c;
		if (c == '+')
			cin >> x;
	}
	
	int ans = 0;
	rep(iter, 0, n) {
		int x = v[iter];
		if (!x) continue;
		// dp[i][j] = number of sets of which contain j elements < X if we consider [0, i) events
		
		vector dp(n + 1, vector(n + 1, 0));
		
		dp[0][0] = 1;
		
		for (int i = 0; i < n; ++i) {
			if (i != iter)
				for (int j = 0; j <= n; ++j)
					dp[i + 1][j] = dp[i][j];

			if (v[i]) {
				if (v[i] < x || (v[i] == x && i < iter)) {
					for (int j = 1; j <= n; ++j)
						inc(dp[i + 1][j], dp[i][j - 1]);
				} else {
					for (int j = 0; j <= n; ++j)
						inc(dp[i + 1][j], dp[i][j]);
				}
			} else {
				for (int j = 1; j <= n; ++j)
					inc(dp[i + 1][j - 1], dp[i][j]);
				
				if (i <= iter)
					inc(dp[i + 1][0], dp[i][0]);
			}
		}
		int cur = 0;
		for (int i = 0; i <= n; ++i)
			inc(cur, dp[n][i]);
		inc(ans, mul(cur, x));
	}
	cout << ans << '\n';
}