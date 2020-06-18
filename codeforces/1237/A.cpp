#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	bool parity = 0;
	rep(i, 0, n) {
		int x; cin >> x;
		if (x & 1) {
			x += parity;
			parity ^= 1;
		}
		if (x < 0) x = -((-x + 1)/2);
		else x = x / 2;
		cout << x << '\n';
	}
}