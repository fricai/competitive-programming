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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 64;
int I[N][N * N / 2];
int M;
int C[N][N];
int tmp[N][N * N / 2];

int add(int x, int y) { return x += y, x < M ? x : x - M; }
int sub(int x, int y) { return x -= y, x < 0 ? x + M : x; }
int mul(ll x, int y) { return x * y % M; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n >> M;

	auto I_max = [&](int n) { return n * (n - 1) / 2; };

	int one = add(0, 1);

	I[1][0] = one;
	for (int m = 2; m <= n; ++m) {
		I[m][0] = I[m - 1][0];
		for (int k = 1; k < m; ++k)
			I[m][k] = add(I[m][k - 1], I[m - 1][k]);
		for (int k = m; k <= I_max(m); ++k)
			I[m][k] = sub(add(I[m][k - 1], I[m - 1][k]), I[m - 1][k - m]);
	}
	
	C[0][0] = one;
	for (int i = 1; i <= n; ++i) {
		C[i][0] = one;
		for (int j = 1; j <= n; ++j)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	}

	int ans = 0;
	
	for (int m = 1; m <= n; ++m) {
		int cur = 0;

		for (int first = 1; first <= m; ++first)
			for (int k = 0; k <= I_max(m); ++k)
				tmp[first][k] = 0;

		for (int first = 1; first <= m; ++first) {
			for (int k = 0; k <= I_max(m - 1); ++k)
				tmp[first][k + first - 1] = I[m - 1][k];
		}

		auto val = [&](int i, int j) -> int {
			if (i < 1 || i > m || j < 0 || j > I_max(m)) return 0;
			return tmp[i][j];
		};
		
		for (int first = 1; first <= m; ++first)
			for (int k = 0; k <= I_max(m); ++k)
				tmp[first][k] = add(val(first, k), sub(add(val(first - 1, k), val(first, k - 1)), val(first - 1, k - 1)));
		
		auto sum = [&](int l, int r, int d, int u) {
			// if (r < l || u < d) return 0;
			return sub(add(val(r, u), val(l - 1, d - 1)), add(val(l - 1, u), val(r, d - 1)));
		};
		
		for (int first = 1; first <= m; ++first)
			for (int k = first - 1; k <= I_max(m); ++k)
				cur = add(cur, mul(sum(first, first, k, k), sum(first + 1, m, 0, k - 1)));

		int f = C[n][m];
		for (int i = 1; i <= n - m; ++i)
			f = mul(f, i);
		ans = add(ans, mul(cur, f));
	}

	cout << ans << '\n';
}