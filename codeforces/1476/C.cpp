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

	vector<ll> a(n), b(n), c(n);
	for (auto &x : c) cin >> x;
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	ll pre = -1e9;
	ll ans = 0;
	rep(i, 1, n) {
		if (a[i] == b[i]) pre = 2;
		if (a[i] < b[i]) pre = max(b[i] - a[i] + 2, a[i] - 1 + c[i - 1] - b[i] + pre + 2);
		if (a[i] > b[i]) pre = max(a[i] - b[i] + 2, b[i] - 1 + c[i - 1] - a[i] + pre + 2);
		ckmax(ans, pre + c[i] - 1);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}