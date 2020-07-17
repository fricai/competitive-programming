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
		int x, y, z; cin >> x >> y >> z;
		int a, b, c;
		if (x == y || y == z || z == x) {
			if (y == z) swap(z, x);
			if (z == x) swap(z, y);
			if (x < z) cout << "NO\n";
			else {
				cout << "YES\n";
				cout << x << ' ' << z << ' ' << z << '\n'; 
			}
		} else cout << "NO\n";
	}
}