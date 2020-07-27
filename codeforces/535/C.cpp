#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll a, b;
ll solve() {
	ll z, t, x; cin >> z >> t >> x; --z;
	if (a + z * b > t) return -1;
	ll l = z + 1, r = 2e6;
	z = a * z + b * z * (z - 1) / 2;
	while (r - l > 1) {
		ll m = l + (r - l) / 2;
		(a + (m - 1) * b <= t && a * m + b * m * (m - 1) / 2 - z <= x * t ? l : r) = m;
	}
	return l;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> a >> b >> q;
	while (q--) cout << solve() << '\n';
}