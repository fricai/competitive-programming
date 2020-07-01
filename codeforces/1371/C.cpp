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

bool f(ll v, ll c, ll n, ll m) {
	// n -> reduces max
	// m -> reduces min

	if (v < c) swap(v, c);
	// WLOG c <= v

	if (v + c < n + m) return false;
	if (m == 0) return true;
	if (n == 0) return m <= c;
	if (m <= c) return true;
	return false;
	// if (n > v - c) {
	// 	n -= v - c;
	// 	v = c;
	// 	// c < m <= v and 0 < n <= v
	// 	return f(c, c, n, m);
	// } else return false;
}


bool solve() {
	ll v, c, n, m; cin >> v >> c >> n >> m;
	return f(v, c, n, m);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "Yes" : "No") << '\n';
}