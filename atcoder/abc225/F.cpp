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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<string> s(n);
	for (auto &x : s)
		cin >> x;
	sort(all(s), [&](auto a, auto b) {
			return a + b > b + a;
			});

	vector dp(n + 1, vector<string>(k + 1));
	rep(i, 0, n) {
		for (int j = 1; j <= k && j <= i; ++j) {
			dp[i + 1][j] = min(dp[i][j], s[i] + dp[i][j - 1]);
		}
		if (i + 1 <= k) dp[i + 1][i + 1] = s[i] + dp[i][i];
	}

	cout << dp[n][k] << '\n';
}
