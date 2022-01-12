#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

constexpr ll inf = 1e12;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, l, k; cin >> n >> l >> k;
	vector<ll> d(n);
	for (auto &x : d) cin >> x;
	d.push_back(l);
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector dp(n + 1, vector(k + 1, inf));
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
			for (int p = i - 1; p >= 0 && j - (i - p - 1) >= 0; --p)
				uin(dp[i][j], a[p] * (d[i] - d[p]) + dp[p][j - (i - p - 1)]);

	/*
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= k; ++j)
			cerr << dp[i][j] << ' ';
		cerr << '\n';
	}
	*/

	cout << *min_element(all(dp[n])) << '\n';
}
