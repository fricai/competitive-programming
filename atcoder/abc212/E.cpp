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

using mint = atcoder::modint998244353;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k; cin >> n >> m >> k;

	vector<vector<int>> g(n);
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	rep(u, 0, n) g[u].push_back(u);

	vector f(2, vector<mint>(n));
	f[0][0] = 1;

	for (int i = 1; i <= k; ++i) {
		mint sum = accumulate(all(f[~i & 1]), mint(0));
		f[i & 1] = vector(n, sum);
		for (int u = 0; u < n; ++u)
			for (auto v : g[u])
				f[i & 1][u] -= f[~i & 1][v];
	}

	cout << f[k & 1][0].val() << '\n';
}
