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

constexpr int mod = 119 << 23|1;
using mint = atcoder::static_modint<mod>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d; cin >> n >> d;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x, --x;

	const int MXS = 1 << (2 * d + 1);
	vector dp(n + 1, vector(MXS, mint(0)));
	dp[0][(1 << (d + 1)) - 1] = 1;
	rep(i, 0, n) {
		rep(S, 0, MXS) {
			const int T = S >> 1;
			rep(j, 0, 2 * d + 1) {
				if (a[i] >= 0 && a[i] != i + j - d)
					continue;
				if (~T >> j & 1)
					dp[i + 1][T | 1 << j] += dp[i][S];
			}
		}
	}
	cout << dp[n][(1 << (d + 1)) - 1].val() << '\n';
}
