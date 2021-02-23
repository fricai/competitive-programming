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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int z, o, k; cin >> z >> o >> k;
	string x, y;

	rep(i, 0, o) x.push_back('1');
	rep(i, 0, z) x.push_back('0');

	if (k == 0) {
		y = x;
	} else if (z == 0 || o == 1) {
		if (k != 0) return cout << "No", 0;
	} else {
		if (k < o) {
			rep(i, 0, o - k) y.push_back('1');
			y.push_back('0');
			rep(i, 0, k) y.push_back('1');
			rep(i, 1, z) y.push_back('0');
			// cerr << "Ahpy";
		} else if (k < o + z - 1) {
			y = "10";
			rep(i, 1, o - 1) y.push_back('1');
			rep(i, 0, k - o + 1) y.push_back('0');
			y.push_back('1');
			rep(i, 0, z - (k - o + 2)) y.push_back('0');
		} else return cout << "No", 0;
	}

	cout << "Yes\n" << x << '\n' << y << '\n';
}