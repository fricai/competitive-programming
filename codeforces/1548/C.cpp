#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define sz(x) int((x).size())

const int X = 3e6 + 20, M = 1e9 + 7;
int f[X], fi[X];
void dec(int &x, int y) { x -= y; if (x < 0) x += M; }
int mul(ll x, int y) { return x * y % M; }
int bpow(int a, ll b) {
	int res = 1;
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1)
			res = mul(res, a);
	return res;
}
int C(int n, int r) {
	if (r < 0 || r > n) return 0;
	return mul(f[n], mul(fi[r], fi[n - r]));
}

signed main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	f[0] = 1;
	rep(i, 1, X) f[i] = mul(i, f[i - 1]);
	fi[X - 1] = bpow(f[X - 1], M - 2);
	per(i, 1, X) fi[i - 1] = mul(i, fi[i]);

	int n, q; cin >> n >> q;

	vector<int> a(3 * (n  + 1));
	for (int i = 1; i <= 3 * (n + 1); ++i)
		a[i - 1] = C(3 * (n + 1), i);

	for (int m = 3 * n + 2; m - 2 >= 0; --m) {
		int x = mul(a[m], 3);
		dec(a[m - 1], x);
		dec(a[m - 2], x);
	}

	while (q--) {
		int x; cin >> x;
		cout << a[x + 2] << '\n';
	}
}