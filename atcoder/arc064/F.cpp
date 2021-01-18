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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using mint = atcoder::static_modint<1000000007>;

int f(int d) { return d >> (~d & 1); }

vector<int> prime_factors;

mint rho(mint k, int n) {
	vector<int> loc;
	for (auto p : prime_factors) if (n % p == 0) loc.push_back(p);
	mint res = 0;
	rep(S, 0, 1 << sz(loc)) {
		int d = 1;
		int mobius = 1;
		rep(i, 0, sz(loc)) if (S >> i & 1) d *= loc[i], mobius *= -1;
		res += mobius * k.pow(((n / d) + 1) / 2);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;

	int m = n;
	for (int d = 2; d * d <= m; ++d)
		if (m % d == 0) {
			while (m % d == 0) m /= d;
			prime_factors.push_back(d);
		}
	if (m != 1) prime_factors.push_back(m);

	mint ans = 0;
	for (int d = 1; d * d <= n; ++d) {
		if (n % d) continue;
		ans += f(d) * rho(k, d);
		if (d * d != n) ans += f(n / d) * rho(k, n / d);
	}
	
	cout << ans.val();
}