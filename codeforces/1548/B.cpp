#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\

int solve() {
	int n; cin >> n;
	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	if (n == 1)
		return 1;
	
	int B = 31 - __builtin_clz(n);
	vector<vector<ll>> st(n, vector(B + 1, 0ll));
	rep(i, 1, n) st[i][0] = abs(a[i] - a[i - 1]);
	for (int b = 0, p = 1; b < B; ++b, p <<= 1)
		for (int i = 1; i + p < n; ++i)
			st[i][b + 1] = gcd(st[i][b], st[i + p][b]);
	auto range_gcd = [&st](int l, int r) -> ll {
		int j = 31 - __builtin_clz(r - l);
		return gcd(st[l][j], st[r - (1 << j)][j]);
	};

	int ans = 1;
	for (int i = 1, j = 1; i < n; ++i) {
		while (j <= i && range_gcd(j, i + 1) == 1) ++j;
		uax(ans, i - j + 2);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}