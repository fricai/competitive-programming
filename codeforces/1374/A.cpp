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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		ll x, y, n; cin >> x >> y >> n;
		ll k = (n/x + 10) * x + y;
		while (k > n) k -= x;
		cout << k << '\n';
	}
}