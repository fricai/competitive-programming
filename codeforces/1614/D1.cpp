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

constexpr int X = 5e6 + 5;
ll dp[X], cnt[X], f[X];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	rep(i, 0, n) {
		int x; cin >> x; ++cnt[x];
	}

	rep(x, 1, X) {
		for (int y = x + x; y < X; y += x) {
			cnt[x] += cnt[y];
		}
	}

	ll ans = 0;
	per(x, 1, X) {
		dp[x] = x * cnt[x];
		for (int y = x; y < X; y += x) {
			uax(dp[x], x * (cnt[x] - cnt[y]) + dp[y]);
		}
		uax(ans, dp[x]);
	}
	cout << ans << '\n';
}
