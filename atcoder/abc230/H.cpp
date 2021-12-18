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

constexpr int mod = 119 << 23|1;
using mint = atcoder::static_modint<mod>;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int w, k; cin >> w >> k;

	vector<mint> g(w + 1);
	rep(i, 0, k) {
		int x; cin >> x;
		g[x] = 1;
	}

	vector<mint> f(w + 1), j(w + 1, g[1]);
	j[0] = 0;

	auto dnc = [&](const auto &rec, int l, int r) -> void {
		if (r - l == 1) {
			f[l] = (f[l] + j[l - 1]) / mint::raw(l - 1);
			auto to_add = mint::raw(l) * (f[l] + g[l]);
			for (int d = l; d <= w; d += l)
				j[d] += to_add;
			return;
		}
		int m = (l + r) / 2;
		rec(rec, l, m);
		auto res = atcoder::convolution(
				vector(begin(f) + l, begin(f) + m),
				vector(begin(j), begin(j) + min(m, r - l))
				);
		for (int i = m; i < r && i - l < sz(res); ++i)
			f[i] += res[i - l];

		res = atcoder::convolution(
				vector(begin(j) + l, begin(j) + m),
				vector(begin(f), begin(f) + min(l, r - l))
				);
		for (int i = m; i < r && i - l < sz(res); ++i)
			f[i] += res[i - l];
		rec(rec, m, r);
	};
	dnc(dnc, 2, w + 1);

	for (int i = 2; i <= w; ++i)
		cout << f[i].val() << '\n';
}
