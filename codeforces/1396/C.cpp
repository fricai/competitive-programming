#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr ll inf = 1e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; ll r[3], d; cin >> n >> r[0] >> r[1] >> r[2] >> d;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	vector dp(n + 1, array<ll, 2>{inf, inf});

	// 1. a[i] pistol shits, AWP boss
	// 2. a[i] + 1 pistol shots, come back later
	// 3. laser gun, come back later

	dp[0][0] = dp[0][1] = -d;

	for (int i = 0; i < n; ++i) {
		auto one = r[0] * a[i] + r[2];
		auto two = (a[i] + 1) * r[0];
		auto three = r[1];
		auto redo = min(two, three);

		uin(dp[i + 1][0], dp[i][0] + d + one);

		uin(dp[i + 1][1], dp[i][0] + d + redo);

		uin(dp[i + 1][0], dp[i][1] + d + one + d + r[0] + d);
		uin(dp[i + 1][0], dp[i][1] + d + redo + d + r[0] + d + r[0]);

		uin(dp[i + 1][1], dp[i][1] + d + redo + d + r[0] + d);
	}
	cout << min(dp[n][0], dp[n - 1][1] + d + r[0] * a[n - 1] + r[2] + d + r[0]) << '\n';
}
