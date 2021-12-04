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

using mint = atcoder::modint;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int p; cin >> p;
	mint::set_mod(p);

	vector<mint> a(p);
	for (auto &x : a) {
		int y; cin >> y;
		x = y;
	}

	vector<mint> b(p), f(p);
	f[0] = 1;
	rep(i, 1, p) f[i] = i * f[i - 1];

	b[0] = a[0];
	b[p - 1] = -a[0];

	for (int k = 1; k < p; ++k) {
		for (int j = 1; j < p; ++j) {
			b[k] -= a[j] * mint(-j).pow(p - 1 - k);
		}
		b[k] = f[p - 1] / (f[k] * f[p - 1 - k]) * b[k];
	}

	for (auto x : b)
		cout << x.val() << ' ';
	cout << '\n';
}
