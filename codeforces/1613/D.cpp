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

constexpr int mod = 998244353;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }

int solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	vector<int> f(n), g(n), h(n);
	// f[i] = non-decreasing sequences ending at i
	// barring non-decreasing sequences, mex correct sequences can be those which go like
	// 	non-decreasing sequence ending with x - 1, ..., x - 1, x + 1, ..., x + 1, x - 1, ..., x - 1, ...
	// g[i] = number of such sequences ending with a[i] = x + 1
	// h[i] = number of such sequences ending with a[i] = x - 1
	
	vector<int> fs(n + 1), gs(n + 1), hs(n + 1);
	vector<int> p(n + 1, -1);

	int ans = 0;
	rep(i, 0, n) {
		if (a[i] == 0) f[i] = 1;
		if (a[i] == 1) g[i] = 1;

		inc(f[i], fs[a[i]]);
		if (a[i] > 0) inc(f[i], fs[a[i] - 1]);
		inc(g[i], gs[a[i]]);
		if (a[i] > 1) {
			inc(g[i], hs[a[i] - 2]);
			inc(g[i], fs[a[i] - 2]);
		}
		if (a[i] + 2 <= n) inc(h[i], gs[a[i] + 2]);
		inc(h[i], hs[a[i]]);

		inc(ans, f[i]);
		inc(ans, g[i]);
		inc(ans, h[i]);

		inc(fs[a[i]], f[i]);
		inc(gs[a[i]], g[i]);
		inc(hs[a[i]], h[i]);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
