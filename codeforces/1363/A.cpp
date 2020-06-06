#include <iostream>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

bool solve() {
	int n, x; cin >> n >> x;
	int odd = 0, even = 0;
	rep(i, 0, n) {
		int a; cin >> a;
		if (a & 1) ++odd; else ++even;
	}
	for (int a = x, b = 0; 0 <= a; --a, ++b)
		if (even >= a && odd >= b && b % 2 == 1)
			return true;
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}