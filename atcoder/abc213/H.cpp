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

	int n, m, t; cin >> n >> m >> t;
	vector<vector<int>> g(n);
	vector<int> a(m), b(m);
	vector p(m, vector(t + 1, mint(0)));
	rep(e, 0, m) {
		cin >> a[e] >> b[e], --a[e], --b[e];
		rep(i, 0, t) {
			int x; cin >> x;
			p[e][i + 1] = x;
		}
		g[a[e]].push_back(e);
		g[b[e]].push_back(e);
	}

	vector f(n, vector(t + 1, mint(0)));
	f[0][0] = 1;
	auto dnc = [&](const auto &self, int l, int r) -> void {
		if (r - l == 1)
			return;

		int m = (l + r) / 2;

		self(self, l, m);
		rep(u, 0, n) {
			auto fu = vector(begin(f[u]) + l, begin(f[u]) + m);
			for (auto e : g[u]) {
				int v = a[e] ^ b[e] ^ u;
				auto rv = atcoder::convolution(fu, {begin(p[e]), begin(p[e]) + r - l});
				rep(i, m, r) f[v][i] += rv[i - l];
			}
		}
		self(self, m, r);
	};
	dnc(dnc, 0, t + 1);
	cout << f[0][t].val() << '\n';
}
