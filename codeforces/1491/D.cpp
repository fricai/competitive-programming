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

const int B = 32;

// bitset<1 << B> reachable[1 << B];

bool solve() {
	ll u, v; cin >> u >> v;
// bool f(ll u, ll v) {
	vector<int> x, y;

	rep(i, 0, B) if (u >> i & 1) x.push_back(i);
	rep(i, 0, B) if (v >> i & 1) y.push_back(i);

	if (sz(x) < sz(y)) return false;
	
	while (!x.empty()) {
		if (x.back() > y.back()) return false;
		assert(x.back() <= y.back());
		int start = x.back();
		int target = y.back();
		x.pop_back();
		y.pop_back();

		if (start < target) while (sz(x) > sz(y)) x.pop_back(), ++start;
	}

	return y.empty();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// rep(i, 1, 1 << B) reachable[i].set(i);
	// per(u, 1, 1 << B)
	// 	for (int v = u; v; --v &= u)
	// 		if (u + v < (1 << B))
	// 		reachable[u] |= reachable[u + v];
	// // cerr << reachable[7][8];
	// rep(u, 1, 1 << B) {
	// 	rep(v, 1, 1 << B) {
	// 		if (reachable[u][v] != f(u, v)) {
	// 			cerr << u << ' ' << v << '\n';
	// 			return 0;
	// 		}
	// 	}
	// }

	int q; cin >> q;
	while (q--) cout << (solve() ? "YES" : "NO") << '\n';
}