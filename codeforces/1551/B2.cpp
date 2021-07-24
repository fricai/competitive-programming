#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int k, n; cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	map<int, vector<int>> f;
	vector<vector<int>> c(k);
	rep(i, 0, n) f[a[i]].push_back(i);

	int p = 0;
	for (auto [x, v] : f) {
		if (sz(v) >= k) {
			rep(i, 0, k)
				c[i].push_back(v[i]);
			continue;
		}
		for (auto i : v) {
			c[p].push_back(i);
			p = (p + 1) % k;
		}
	}
	int mn = n;
	rep(i, 0, k) uin(mn, sz(c[i]));
	rep(i, 0, k) c[i].resize(mn);
	vector<int> ans(n, 0);
	rep(i, 0, k)
		for (auto j : c[i])
			ans[j] = i + 1;

	for (auto x : ans)
		cout << x << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}