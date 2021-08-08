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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x, --x;

	// f[l][b] = longest non-dec subseqeunce in [0, l) ending with b
	vector f(n + 1, vector(2, 0));
	for (int i = 0; i < n; ++i) {
		f[i + 1] = f[i];
		if (a[i] == 0)
			f[i + 1][0] = f[i][0] + 1;
		else
			f[i + 1][1] = max(f[i][0], f[i][1]) + 1;
	}
	
	// g[r][b] = longest non-dec subsequence in [r, n) starting with b
	vector g(n + 1, vector(2, 0));
	for (int i = n; i > 0; --i) {
		g[i - 1] = g[i];
		if (a[i - 1] == 0)
			g[i - 1][0] = max(g[i][0], g[i][1]) + 1;
		else
			g[i - 1][1] = g[i][1] + 1;
	}

	// h[l][r][b] = longest non-inc subsequence ending with b in [l, r]
	vector h(n, vector(n, vector(2, 0)));
	for (int l = 0; l < n; ++l) {
		h[l][l][a[l]] = 1;
		for (int r = l + 1; r < n; ++r) {
			h[l][r] = h[l][r - 1];
			if (a[r] == 0)
				h[l][r][0] = max(h[l][r - 1][0], h[l][r - 1][1]) + 1;
			else
				h[l][r][1] = h[l][r - 1][1] + 1;
		}
	}
	
	int ans = max(f[n][0], f[n][1]);
	for (int l = 0; l < n; ++l) {
		vector cnt(2, 0);
		for (int r = l; r < n; ++r) {
			// reverse [l, r]
			++cnt[a[r]];
			uax(ans, f[l][0] + cnt[0] + g[r + 1][0]);
			uax(ans, f[l][0] + max({cnt[0], cnt[1], h[l][r][0], h[l][r][1]}) + g[r + 1][1]);
			uax(ans, f[l][1] + cnt[1] + g[r + 1][1]);
		}
	}
	cout << ans << '\n';
}