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

const ll inf = 1e18;

ll solve() {
	int n; cin >> n;
	vector<ll> c(n);
	for (auto &x : c) cin >> x;
	
	ll mn[2] = {c[0], inf}, sum = c[0], x[2] = {n, n + 1};
	ll ans = inf;
	for (int i = 1; i < n; ++i) {
		--x[i & 1];
		ckmin(mn[i & 1], c[i]);
		sum += c[i];
		ckmin(ans, mn[0] * x[0] + mn[1] * x[1] + sum - mn[0] - mn[1]);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}