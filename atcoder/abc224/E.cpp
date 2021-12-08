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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w, n; cin >> h >> w >> n;

	vector<int> r(n), c(n), a(n);
	rep(i, 0, n) cin >> r[i] >> c[i] >> a[i], --r[i], --c[i];

	vector<vector<int>> s(h), t(w);

	vector<int> ord(n);
	iota(all(ord), 0);
	sort(all(ord), [&](int i, int j) {
			return a[i] > a[j];
			});

	for (auto i : ord) {
		s[r[i]].push_back(i);
		t[c[i]].push_back(i);
	}

	vector<int> sm(h), tm(w), dp(n);

	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && a[ord[i]] == a[ord[j]])
			++j;
		for (int k = i; k < j; ++k) {
			int u = ord[k];
			dp[u] = max(sm[r[u]], tm[c[u]]);
		}
		for (int k = i; k < j; ++k) {
			int u = ord[k];
			uax(sm[r[u]], 1 + dp[u]);
			uax(tm[c[u]], 1 + dp[u]);
		}
	}

	for (auto x : dp)
		cout << x << '\n';
}
