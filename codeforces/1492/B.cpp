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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n; cin >> n;
	vector<int> p(n);
	for (auto &x : p) cin >> x, --x;
	vector<int> inv(n);
	rep(i, 0, n) inv[p[i]] = i;
	vector<bool> dead(n);

	vector<int> ans;
	int lst = n;
	per(x, 0, n) {
		if (dead[x]) continue;
		rep(i, inv[x], lst) {
			ans.push_back(p[i]);
			dead[p[i]] = true;
		}
		lst = inv[x];
	}

	assert(sz(ans) == n);
	for (auto x : ans) cout << x + 1 << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}