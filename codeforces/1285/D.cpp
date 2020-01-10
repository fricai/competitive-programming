#include <algorithm>
#include <iostream>
#include <bitset>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1 << 17, B = 30;
int n, a[N];

int pos(int l, int r, int p) {
	rep(i, l, r)
		if ((a[i] >> p) & 1)
			return i;
	return r;
}

int solve(int l = 0, int r = n, int b = B - 1) { // [l, r)
	if (b < 0) return 0;
	int x = pos(l, r, b);
	if (x == l || x == r) return solve(l, r, b - 1);
	else return (1 << b) | min(solve(l, x, b - 1), solve(x, r, b - 1));
}

signed main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	cin >> n;
	rep(i, 0, n) cin >> a[i];
	sort(a, a + n);
	cout << solve();
}