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

void FST(vector<mint>& a, bool inv) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step)
			rep(j, i, i + step) {
				auto &u = a[j], &v = a[j + step];
				tie(u, v) = pair(u + v, u - v);
			}
	}
	if (inv) for (auto& x : a) x /= sz(a);
}

mint f(mint x, int n) {
	if (n == 1)
		return x;
	if (n & 1) {
		return x + (1 + x) * f(x * x, (n - 1) / 2);
	}
	return x + x * f(x, n - 1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<int> a(k);
	for (auto &x : a)
		cin >> x;
	int mx = *max_element(all(a));
	int sz = 1;
	while (sz <= mx) sz <<= 1;

	vector<mint> c(sz);
	for (auto x : a)
		++c[x];

	FST(c, false);
	for (auto &x : c) x = f(x, n);
	FST(c, true);

	mint ans = 0;
	rep(i, 1, sz) ans += c[i];
	cout << ans.val() << '\n';
}
