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
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 7, M = 1e9 + 7;

using mint = atcoder::static_modint<M>;

using matrix = vector<vector<mint>>;

matrix operator*(const matrix &a, const matrix &b) {
	int n = sz(a), m = sz(b[0]), p = sz(a[0]);
	assert(p == sz(b));
	matrix c(n, vector<mint>(m, 0));
	rep(i, 0, n)
		rep(j, 0, m)
			rep(k, 0, p)
				c[i][j] += a[i][k] * b[k][j];
	return c;
}

vector<int> g[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k; cin >> n >> m >> k;
	matrix b(n, vector<mint>(n, 0));

	vector<vector<mint>> a(n);
	for (auto &x : a) {
		int y; cin >> y;
		x = {y};
	}
	
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	rep(u, 0, n) {
		mint x = 1;
		x /= 2 * m;
		b[u][u] = 1 - sz(g[u]) * x;
		for (auto v : g[u]) b[u][v] = x;
	}

	matrix res = b;
	rep(u, 0, n) {
		rep(v, 0, n) res[u][v] = 0;
		res[u][u] = 1;
	}

	for (; k; k >>= 1, b = b * b)
		if (k & 1) res = res * b;

	auto F = res * a;
	for (auto x : F) cout << x[0].val() << '\n';
}