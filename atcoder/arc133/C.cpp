#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m, k; cin >> n >> m >> k;
	using mint = atcoder::modint;
	mint::set_mod(k);

	vector<mint> a(n), b(m);
	for (auto &x : a) { int y; cin >> y; x = y; }
	for (auto &x : b) { int y; cin >> y; x = y; }

	if (accumulate(all(a), mint(0)) != accumulate(all(b), mint(0)))
		return cout << "-1\n", 0;

	ll mx = 0;
	rep(_, 0, 2) {
		ll cur = 0;
		rep(i, 0, n) cur += (-(a[i] + m)).val();
		uax(mx, cur);
		swap(a, b);
		swap(n, m);
	}
	cout << n * m * (k - 1) - mx << '\n';
}
