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

constexpr int mod = 119 << 23|1, N = 4e5 + 10;
using mint = atcoder::static_modint<mod>;

mint fac[N], ifac[N];
mint C(int n, int r) {
	if (r < 0 || r > n) return 0;
	return fac[n] * ifac[r] * ifac[n - r];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fac[0] = 1;
	rep(i, 1, N) fac[i] = mint::raw(i) * fac[i - 1];
	ifac[N - 1] = 1 / fac[N - 1];
	per(i, 1, N) ifac[i - 1] = mint::raw(i) * ifac[i];

	int n, m, k; cin >> n >> m >> k;
	
	if (k == 0) {
		cout << (C(n + m - 1, 2 * m - 1) * fac[m]).val() << '\n';
		return 0;
	}

	vector<int> a(k);
	for (auto &x : a)
		cin >> x;

	auto gen_end = [&](int r) {
		vector<mint> f(r);
		rep(i, 0, r) f[i] = C(r + i - 1, 2 * i);
		return f;
	};
	auto gen_mid = [&](int r) {
		vector<mint> f(r - 1);
		rep(i, 0, r - 1) f[i] = C(r + i - 1, 2 * i + 1);
		return f;
	};

	vector<vector<mint>> bot;

	bot.push_back(gen_end(a[0]));
	rep(i, 1, k) bot.push_back(gen_mid(a[i] - a[i - 1] + 1));
	bot.push_back(gen_end(n - a[k - 1] + 1));

	auto dnc = [&](const auto &self, int l, int r) -> vector<mint> {
		if (r - l == 1) return bot[l];
		int m = (l + r) / 2;
		return atcoder::convolution(self(self, l, m), self(self, m, r));
	};

	cout << (fac[m - k] * dnc(dnc, 0, sz(bot))[m - k]).val() << '\n';
}