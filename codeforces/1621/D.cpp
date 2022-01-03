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

ll solve() {
	int n; cin >> n;
	vector c(2 * n, vector(2 * n, 0));
	for (auto &v : c)
		for (auto &x : v)
			cin >> x;

	ll ans = 0;
	rep(i, 0, n) rep(j, 0, n) ans += c[i + n][j + n];

	return ans + min({c[0][n], c[0][2 * n - 1], c[n - 1][n], c[n - 1][2 * n - 1], c[n][0], c[2 * n - 1][0], c[n][n - 1], c[2 * n - 1][n - 1]});
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
