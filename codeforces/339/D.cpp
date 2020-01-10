#include <iostream>
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const int B = 17, N = 1 << B;
int t[N << 1];

int f(int x, int y, bool b) {
	return (b ? (x | y) : (x ^ y));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int b, q; cin >> b >> q;
	int n = 1 << b;
	rep(i, 0, n) cin >> t[i + n];
	for (int m = n, x = 1; m; m >>= 1, x ^= 1)
		for (int i = m - 1; i >= (m >> 1); --i)
			t[i] = f(t[i << 1], t[i << 1|1], x);
	while (q--) {
		int p; cin >> p; --p;
		p += n; cin >> t[p];
		for (bool b = 1; p >>= 1; b ^= 1)
			t[p] = f(t[p << 1], t[p << 1|1], b);
		cout << t[1] << '\n';
	}
}