#include <bits/stdc++.h>

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

constexpr int mod = 1e9 + 7, M = 5e5 + 5, C = 1e6 + 20;
int fac[M], f[2 * C];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fac[0] = 1;
	rep(i, 1ll, M) fac[i] = i * fac[i - 1] % mod;

	int m; cin >> m;
	rep(i, 0, m) {
		int c; cin >> c;
		++f[1 - c + C];
		--f[c + 1 + C];
	}

	ll ans = 0, ways = 1;
	auto g = [](ll x, ll d) -> ll { return (d * x + d * (d - 1) / 2) % mod; };
	for (int i = 2, cnt = 1; i < 2 * C; ++i) {
		f[i] += f[i - 2];
		ans = (ans + g(cnt, f[i]) * (i - C)) % mod;
		ways = ways * fac[f[i]] % mod;
		cnt = (cnt + f[i]) % mod;
	}
	cout << ans << ' ' << ways << '\n';
}
