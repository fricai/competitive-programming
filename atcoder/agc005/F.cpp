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

constexpr int mod = 924844033;
using mint = atcoder::static_modint<mod>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<vector<int>> g(n);
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> sub(n);
	auto init = [&](const auto &dfs, int u, int p) -> void {
		sub[u] = 1;
		for (auto v : g[u])
			if (v != p) {
				dfs(dfs, v, u);
				sub[u] += sub[v];
			}
	};
	init(init, 0, 0);

	vector<mint> c(n + 1);
	rep(u, 1, n) ++c[sub[u]], ++c[n - sub[u]];

	vector<mint> fac(n + 1), ifac(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = mint::raw(i) * fac[i - 1];
	ifac.back() = 1 / fac.back();
	for (int i = n; i >= 1; --i) ifac[i - 1] = mint::raw(i) * ifac[i];


	for (int i = 0; i <= n; ++i)
		c[i] *= fac[i];

	auto res = atcoder::convolution(c, {rall(ifac)});
	for (int k = 1; k <= n; ++k)
		cout << (mint::raw(n) * (fac[n] * ifac[k] * ifac[n - k]) - res[k + n] * ifac[k]).val() << '\n';
}
