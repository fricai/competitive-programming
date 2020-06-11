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

bool intersect(int l, int r, int lo, int hi) {
	if (lo <= r && r <= hi) return true;
	if (lo <= l && l <= hi) return true;
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n, x, m;
		cin >> n >> x >> m;
		int left = x, right = x;
		while (m--) {
			int l, r; cin >> l >> r;
			if (intersect(left, right, l, r))
				ckmin(left, l), ckmax(right, r);
		}
		cout << (right - left + 1) << '\n';
	}
}