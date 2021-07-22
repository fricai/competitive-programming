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
	int n, m; cin >> n >> m;
	
	vector<int> p(n);
	for (auto &x : p) cin >> x, --x;
	vector<int> cnt(n);
	rep(i, 0, n) ++cnt[(i - p[i] + n) % n];

	vector<int> ans;
	rep(k, 0, n) {
		if (cnt[k] < n - 2 * m)
			continue;
		
		vector<int> q(n);
		rep(i, 0, n) q[i] = p[(i + k) % n];
		
		vector<bool> vis(n);
		int cnt = 0;
		rep(i, 0, n) {
			if (vis[i]) continue;
			for (int j = i; !vis[j]; j = q[j])
				vis[j] = 1;
			++cnt;
		}
		if (n - cnt <= m)
			ans.push_back(k);
	}
	
	cout << sz(ans) << ' ';
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