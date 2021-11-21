#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int mod = 119 << 23|1, X = 1e5 + 10;
int dp[2][X];

int mul(ll x, int y) { return x * y % mod; }
int add(int x, int y) { x += y; return x < mod ? x : x - mod; }
int sub(int x, int y) { x -= y; return x < 0 ? x + mod : x; }

int solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	// vector<map<int, int>> mem(n - 1);
	// auto f = [&](const auto &self, int i, int x) -> int {
	// 	if (i < 0) {
	// 		assert(x > 0);
	// 		return 0;
	// 	}

	// 	int r = (a[i] - 1) / x;
	// 	auto it = mem[i].find(r);
	// 	if (it != end(mem[i])) {
	// 		return it->second;
	// 	}

	// 	return mem[i][r] = add(mul(i + 1, r), self(self, i - 1, a[i] / (r + 1)));
	// };

	int ans = 0;

	vector<vector<int>> opt(2);
	for (int i = 0; i < n - 1; ++i) {
		assert(opt[i & 1].empty());

		for (int d = 1; d * d <= a[i + 1]; ++d) {
			opt[i & 1].push_back(d);
			opt[i & 1].push_back(a[i + 1] / d);
		}
		for (auto x : opt[i & 1]) {
			int r = (a[i] - 1) / x;
			dp[i & 1][x] = add(mul(i + 1, r), dp[~i & 1][a[i] / (r + 1)]);
		}
		ans = add(ans, dp[i & 1][a[i + 1]]);

		for (auto x : opt[~i & 1]) {
			dp[~i & 1][x] = 0;
		}
		opt[~i & 1].clear();
	}
	for (auto x : opt[n & 1]) {
		dp[n & 1][x] = 0;
	}

	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
