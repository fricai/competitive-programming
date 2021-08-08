#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int X = 1e6 + 50, M = 1e9 + 7;
int mul(ll x, int y) { return x * y % M; }
int add(int x, int y) { return x += y, x < M ? x : x - M; }
int sub(int x, int y) { return x -= y, x < 0 ? x + M : x; }
int bpow(int a, ll b) {
	int res = 1;
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1)
			res = mul(res, a);
	return res;
}

int inv[X];
int C(int n, int r) {
	if (r < 0 || r > n)
		return 0;
	int res = 1;
	for (int i = 0; i < r; ++i) {
		res = mul(res, n - i);
		res = mul(res, inv[i + 1]);
	}
	return res;
}

int s[4][X];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	inv[1] = 1;
	rep(i, 2, X) inv[i] = M - mul(M / i, inv[M % i]);

	s[0][0] = 1;
	rep(i, 0, 4)
		rep(x, 1, X)
			s[i][x] = add(mul(2, bpow(x, i + i)), s[i][x - 1]);
	// s[i][x] = sum y^(2i) over |y| <= x

	ll m; cin >> m;
	int k = m % M;

	vector b(4, 0);

	b[0] = C(k + 2, 3);
	b[1] = add(mul(k, inv[2]), mul(2, inv[3]));
	b[2] = sub(0, add(mul(k, inv[2]), 1));
	b[3] = inv[3];
	
	vector a(4, vector(4, 0));
	rep(k, 0, 4)
		rep(i, 0, k + 1)
			a[i][k - i] = add(a[i][k - i],  mul(C(k, i), b[k]));
	
	int ans = 0;
	for (ll x = 0, y = sqrt(m) + 10; x * x <= m; ++x) {
		while (x * x + y * y > m) --y;
		int cur = 0;
		rep(i, 0, 4) {
			int tmp = 0;
			rep(j, 0, 4) tmp = add(tmp, mul(a[i][j], s[j][y]));
			cur = add(cur, mul(tmp, bpow(x, i + i)));
		}
		ans = add(ans, cur);
		if (x) ans = add(ans, cur);
	}
	cout << ans << '\n';
}