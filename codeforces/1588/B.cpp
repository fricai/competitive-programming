#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll query(int l, int r) {
	cout << "? " << l << ' ' << r << endl;
	ll x; cin >> x;
	return x;
}

signed main() {
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll tot = query(1, n);
		int l = 1, r = n;
		while (r - l > 1) {
			int m = (l + r) / 2;
			(query(m, n) == tot ? l : r) = m;
		}
		int i = l;
		int j = i + tot - query(i + 1, n) + 1;
		int k = (tot - 1ll * (j - i) * (j - i - 1) / 2) - query(j + 1, n) + j;

		cout << "! " << i << ' ' << j << ' ' << k << endl;
	}
}
