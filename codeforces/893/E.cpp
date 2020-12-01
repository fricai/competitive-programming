#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int M = 1e9 + 7;
const int MX = 1 << 21;
ll f[MX], fi[MX], inv[MX];

ll nCr(int n, int k) {
	if (k < 0 || k > n) return 0;
	return f[n] * fi[n - k] % M * fi[k] % M;
}

int solve() {
	vector<int> cnt;
	int x, y; cin >> x >> y;

	ll res = 1;
	auto f = [&](int k) { res = res * nCr(y + k - 1, k) % M; };

	for (int d = 2; d * d <= x; ++d) {
		if (x % d == 0) {
			int k = 0;
			while (x % d == 0) ++k, x /= d;
			f(k);
		}
	}
	if (x != 1) f(1);
	--y;
	ll t = 2;
	for ( ; y; y >>= 1, t = t * t % M)
		if (y & 1) res = res * t % M;
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	inv[1] = f[0] = f[1] = fi[0] = fi[1] = 1;
	rep(i, 2, MX) {
		inv[i] = M - (M / i) * inv[M % i] % M;
		f[i] = i * f[i - 1] % M;
		fi[i] = inv[i] * fi[i - 1] % M;
	}

	int q; cin >> q;
	while (q--) cout << solve() << '\n';
}