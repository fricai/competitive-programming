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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using mint = atcoder::modint998244353;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	map<ll, int> mp;

	ll sum = 0;

	vector<mint> dp(n + 1);
	dp[1] = 1;

	mint ans = 1;

	for (int i = 1; i < n; ++i) {
		sum += a[i];
		int j = mp[sum];
		dp[i + 1] = dp[i] + dp[i] - dp[j];
		ans += dp[i + 1] - dp[i];
		mp[sum] = i;
	}

	cout << ans.val() << '\n';
}
