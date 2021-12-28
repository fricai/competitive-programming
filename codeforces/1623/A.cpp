#include <bits/stdc++.h>

using namespace std;

int c(int a, int b, int n) {
	if (a <= b)
		return b - a;
	return (n - a) + (n - b);
}

int solve() {
	int n, m, rb, cb, rd, cd; cin >> n >> m >> rb >> cb >> rd >> cd;
	return min(c(rb, rd, n), c(cb, cd, m));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
