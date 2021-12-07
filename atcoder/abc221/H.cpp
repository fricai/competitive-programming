#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/convolution>

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

using mint = atcoder::modint998244353;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	vector f(n + 1, vector<mint>(n + 1));
	auto g = f;
	f[0][0] = mint::raw(1);
	for (int i = 0; i < m; ++i)
		g[0][i] = f[0][0];

	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= n; ++y) {
			// g[x][y] = same thing but last need not be positive
			for (int z = 1; y * z <= x; ++z)
				f[x][y] += g[x - y * z][y - 1];
			g[x][y] = f[x][y] + g[x][y - 1];
			if (y >= m) g[x][y] -= f[x][y - m];
		}
	}

	for (int k = 1; k <= n; ++k) {
		cout << f[n][k].val() << '\n';
	}
}
