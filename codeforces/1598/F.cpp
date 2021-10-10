#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a >= b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a <= b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int inf = 1e9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<vector<int>> a(n);

	vector<int> sum(n), low(n);

	rep(i, 0, n) {
		string s; cin >> s;

		a[i].assign(sz(s) + 1, 0);
		rep(j, 0, sz(s)) {
			sum[i] += s[j] == '(' ? +1 : -1;
			if (uax(low[i], -sum[i]))
				++a[i][low[i]];
		}

		/*
		for (auto x : a[i])
			cerr << x << ' ';
		cerr << '\n';
		*/
	}

	vector<int> dp(1 << n, -inf);
	dp[0] = 0;

	int ans = 0;
	rep(S, 0, 1 << n) {
		uax(ans, dp[S]);

		int count = 0;
		rep(i, 0, n)
			if (S >> i & 1)
				count += sum[i];
		rep(i, 0, n) {
			if (S >> i & 1)
				continue;
			int del = 0 <= count && count < sz(a[i]) ? a[i][count] : 0;
			uax(count < low[i] ? ans : dp[S | 1 << i], dp[S] + del);
		}
	}
	cout << ans << '\n';
}
