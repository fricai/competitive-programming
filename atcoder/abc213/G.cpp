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
const mint two = 2;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int n, m; cin >> n >> m;
	vector<int> g(n);
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u] |= 1 << v;
		g[v] |= 1 << u;
	}

	vector<mint> sub(1 << n), conn(1 << n);
	rep(S, 0, 1 << n) {
		int e = 0;
		rep(u, 0, n)
			if (S >> u & 1)
				e += __builtin_popcount(g[u] & S);
		sub[S] = two.pow(e / 2);
	}

	rep(S, 1, 1 << n) {
		int u = 31 - __builtin_clz(S);
		conn[S] = sub[S];
		int U = S ^ (1 << u);
		for (int T = U; T;) {
			--T &= U;
			conn[S] -= conn[T | 1 << u] * sub[U ^ T];
		}
	}

	vector<mint> ans(n);

	int V = (1 << n) - 1;
	rep(S, 0, 1 << n) {
		if (~S & 1)
			continue;
		mint ok = conn[S] * sub[V ^ S];
		rep(u, 1, n)
			if (S >> u & 1)
				ans[u] += ok;
	}

	rep(u, 1, n) cout << ans[u].val() << '\n';
}
