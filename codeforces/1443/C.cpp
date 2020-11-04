#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 18;
const ll inf = 1e18;
int a[N], b[N];
int n;

bool ok(ll x) {
	ll s = 0;
	rep(i, 0, n) if (a[i] > x) s += b[i];
	return s <= x;
}

ll solve() {
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	ll l = 0, r = inf;
	while (r - l > 1) {
		ll m = l + (r - l + 1) / 2;
		// (l, r]
		if (ok(m)) r = m;
		else l = m;
	}
	return r;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}