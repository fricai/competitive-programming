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

const int M = 1e9 + 7, N = 1 << 17;
ll inv[N], fac[N], fi[N];

int bpow(ll a, ll b) {
	int res = 1;
	for (; b; b >>= 1, a = a * a % M)
		if (b & 1) res = res * a % M;
	return res;
}

ll nCr(int n, int r) {
	if (r < 0 || r > n) return 0;
	return fac[n] * fi[r] % M * fi[n - r] % M;
}

ll solve(int f, int w, int h) {
	ll res = 0;
	for (int k = 0; k <= f + 1 && k * h < w; ++k)
		res = (res + nCr(f + 1, k) * nCr(w - k * h - 1, k - 1)) % M;
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	inv[1] = fac[0] = fac[1] = fi[0] = fi[1] = 1;
	rep(i, 2, N) {
		inv[i] = (M - inv[M % i] * (M / i) % M) % M;
		fac[i] = i * fac[i - 1] % M;
		fi[i] = inv[i] * fi[i - 1] % M;
	}

	int f, w, h; cin >> f >> w >> h;
	cout << (w ? solve(f, w, h) * bpow(solve(f, w, 0), M - 2) % M : 1);
}