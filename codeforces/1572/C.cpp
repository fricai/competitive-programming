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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x, --x;

	vector<int> nxt(n, n);
	vector<int> pre(n, n);
	per(i, 0, n) {
		nxt[i] = pre[a[i]];
		pre[a[i]] = i;
	}

	vector dp(n + 1, vector(n, -1));
	per(i, 0, n) {
		rep(j, i, n) {
			dp[i][j] = 1 + (i + 1 < n ? dp[i + 1][j] : -1);
			for (int v = nxt[i]; v <= j; v = nxt[v]) {
				uin(dp[i][j], 1 + (i + 1 < n && v > 0 ? dp[i + 1][v - 1] : -1) + dp[v][j]);
			}
		}
	}
	/*
	rep(i, 0, n) {
		rep(j, 0, n)
			cerr << dp[i][j] << ' ';
		cerr << '\n';
	}
	*/
	return dp[0][n - 1];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
