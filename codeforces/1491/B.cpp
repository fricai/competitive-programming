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

ll solve() { 
	int n; cin >> n;
	ll u, v; cin >> u >> v;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	rep(i, 1, n) if (abs(a[i] - a[i - 1]) > 1) return 0;

	bool all_equal = true;
	rep(i, 1, n) all_equal &= a[i] == a[i - 1];
	if (all_equal) return min(v + u, v + v);
	return min(u, v);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}