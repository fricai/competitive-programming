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


#pragma GCC optimize ("trapv")

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

signed main() {
	ios::sync_with_stdio(false);
	
	int n; cin >> n;
	rep(i, 0, n) {
		rep(j, 0, n) cout << (j & 1 ? 1ll << (i + j - 1) : 0) << ' ';
		cout << endl;
	}
	int q; cin >> q;
	while (q--) {
		ll res; cin >> res;
		cout << "1 1" << endl;
		int x = 1, y = 1;
		rep(i, 0, 2 * (n - 1)) {
			if ((x & 1) ^ (res & 1)) ++y; else ++x;
			cout << y << ' ' << x << endl;
			res >>= 1;
		}
	}
}