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

const int N = 1 << 18, inf = 1e9, M = 119 << 23 | 1;

int add(int x, int y) { return x += y, x < M ? x : x - M; }
int sub(int x, int y) { return x -= y, x < 0 ? x + M : x; }

int t[N << 1];

void update(int p, int v) {
	for (t[p += N] = v; p >>= 1; )
		t[p] = add(t[p << 1], t[p << 1|1]);
}

int query(int l, int r) {
	int res = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = add(res, t[l++]);
		if (r & 1) res = add(res, t[--r]);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> x(n), y(n), s(n), p(n);
	rep(i, 0, n) cin >> x[i] >> y[i] >> s[i];

	// p[i] = min j such that x[j] > y[i]
	rep(i, 0, n)
		p[i] = upper_bound(all(x), y[i]) - begin(x);

	// min_st q_finder;
	// vector<int> q(n);
	// rep(i, 0, n) {
	// 	q[i] = min(p[i], q_finder.query(p[i], i));
	// 	q_finder.set(i, q[i]);
	// }
	/*
		dp[i]
			= cost to reach i again if you teleport at i and everything before i has been set
	*/
	
	vector dp(n, 0);
	for (int i = 0; i < n; ++i) {
		dp[i] = add(sub(x[i], y[i]), query(p[i], i));
		// for (int j = p[i]; j < i; ++j)
		// 	dp[i] = add(dp[i], dp[j]);
		update(i, dp[i]);
	}

	int r = -1;
	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (s[i]) {
			ans = add(ans, sub(x[i], r < 0 ? 0 : x[r]));
			ans = add(ans, dp[i]);
			r = i;
		}
	ans = add(ans, sub(x[n - 1] + 1, r < 0 ? 0 : x[r]));

	cout << ans << '\n';
}