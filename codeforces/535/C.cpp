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
	ll z, t, x; cin >> z >> t >> x;
	if (a + (z - 1) * b > t) return -1;
	ll l = z, r = 2e9;
	while (r - l > 1) {
		ll m = l + (r - l) / 2;
		(a + (m - 1) * b <= t && (m - z + 1) * a + (m * (m - 1) - (z - 1) * (z - 2)) / 2 * b <= x * t ? l : r) = m;
	}
	return l;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> a >> b >> q;
	while (q--) cout << solve() << '\n';
}