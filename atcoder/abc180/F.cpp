#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using mint = atcoder::modint1000000007;
const mint half = mint(1) / 2;

constexpr int N = 300 + 5;
mint f[N], fi[N], path[N], cycle[N];
mint C(int n, int r) {
	if (r < 0 || r > n) return 0;
	return f[n] * fi[r] * fi[n - r];
}

mint solve(int N, int M, int L) {
	vector g(N + 1, vector(M + 1, mint(0)));

	g[0][0] = 1;
	for (int n = 0; n <= N; ++n) {
		for (int m = 0; m <= M; ++m) {
			for (int k = 1; k <= L && n + k <= N && m + k - 1 <= M; ++k) {
				g[n + k][m + k - 1] += C(N - n - 1, k - 1) * g[n][m] * path[k];
			}
			for (int k = 2; k <= L && n + k <= N && m + k <= M; ++k) {
				g[n + k][m + k] += C(N - n - 1, k - 1) * g[n][m] * cycle[k];
			}
		}
	}

	return g[N][M];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = 1;
	rep(i, 1, N) f[i] = i * f[i - 1];
	fi[N - 1] = 1 / f[N - 1];
	per(i, 1, N) fi[i - 1] = i * fi[i];

	path[1] = 1;
	rep(i, 2, N) path[i] = f[i] * half;
	rep(i, 2, N) cycle[i] = path[i - 1];

	int n, m, l; cin >> n >> m >> l;
	cout << (solve(n, m, l) - solve(n, m, l - 1)).val() << '\n';
}
