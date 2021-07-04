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
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using mint = atcoder::modint1000000007;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n; int m, k; cin >> n >> m >> k;
	
	const int U = 2.5e6 + 2;

	vector<mint> f(U + 1, 0);
	for (int i = 1; i <= U; ++i)
		f[i] = mint(i).pow(k);
	
	for (int j = 1; j <= m; ++j)
		for (int i = 1; i <= U; ++i)
			f[i] += f[i - 1];
	
	vector<mint> fac(U + 1);
	fac[0] = 1;
	for (int i = 1; i <= U; ++i)
		fac[i] = i * fac[i - 1];

	vector<mint> L(U + 1), R(U + 1);
	L.front() = 1;
	for (int i = 1; i <= U; ++i)
		L[i] = L[i - 1] * (n - i);
	
	R.back() = 1;
	for (int i = U; 1 <= i; --i)
		R[i - 1] = R[i] * (n - i);
	
	mint ans = 0;
	for (int i = 1; i <= U; ++i) {
		mint del = L[i - 1] * R[i];		
		del /= fac[U - i] * fac[i - 1];
		if ((U ^ i) & 1) ans -= del * f[i];
		else ans += del * f[i];
	}

	cout << ans.val() << '\n';
}