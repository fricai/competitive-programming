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

const int M = 1e9 + 7;

int N, n, m;
bool valid(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }
int hsh(int x, int y) { return m * x + y; }

void add(int &x, int y) { x += y; if (M <= x) x -= M; }

using vi = vector<int>;
using V = vector<vi>;
V operator*(const V &a, const V &b) {
	V c(N, vi(N, 0));
	rep(i, 0, N)
		rep(j, 0, N)
			rep(k, 0, N)
				add(c[i][j], (ll) a[i][k] * b[k][j] % M);
	return c;
}
V& operator*=(V &x, const V &y) { return x = x * y; }

V binpow(V a, int n) {
	V res(N, vi(N, 0));
	rep(i, 0, N) res[i][i] = 1;
	for (; n; n >>= 1, a *= a)
		if (n & 1) res *= a;
	return res;
}

const int MX = 30;
bool dead[MX][MX];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> n >> m >> q;
	N = n * m;

	V A;


	auto g = [&](int u, int i, int j) {
		if (valid(i, j) && !dead[i][j]) A[u][hsh(i, j)] = 1;
	};

	V C(N, vi(N, 0));
	rep(x, 0, N) C[x][x] = 1;

	int p = 1;
	while (q--) {
		int c, i, j, t; cin >> c >> i >> j >> t; --i; --j;

		A = V(N, vi(N, 0));
		rep(i, 0, n) {
			rep(j, 0, m) {
				if (dead[i][j]) continue;
				int u = hsh(i, j);
				A[u][u] = 1;
				g(u, i + 1, j);
				g(u, i - 1, j);
				g(u, i, j + 1);
				g(u, i, j - 1);
			}
		}

		C *= binpow(A, t - p);

		if (c != 1) dead[i][j] ^= 1;
		else cout << C[0][hsh(i, j)] << '\n';

		p = t;
	}
}