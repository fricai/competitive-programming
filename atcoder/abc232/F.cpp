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

constexpr ll inf = 1e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; ll x, y; cin >> n >> x >> y;
	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x, --x;
	for (auto &x : b) cin >> x, --x;

	vector dp(1 << n, inf);
	dp[0] = 0;
	rep(S, 1, 1 << n) {
		rep(i, 0, n) {
			if (~S >> i & 1)
				continue;
			uin(dp[S], dp[S ^ (1 << i)]
					+ abs(a[i] - b[__builtin_popcount(S) - 1]) * x
					+ __builtin_popcount(~S & ((1 << i) - 1)) * y
					);
		}
	}
	cout << dp.back() << '\n';
}
