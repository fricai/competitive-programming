#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)
#define ff first
#define ss second

using ll = int64_t;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

using vi = vector<int>;
using vvi = vector<vector<int>>;
constexpr int M = 1e9 + 7;

int n;

vvi operator*(const vvi& a, const vvi& b) {
	vvi c(n, vi(n));
	rep(i, 0, n)
		rep(j, 0, n)
			rep(k, 0, n)
				c[i][j] = (c[i][j] + 1ll * a[i][k] * b[k][j]) % M;
	return c;
}

vvi bpow(vvi a, ll b) {
	assert(b > 0);
	vvi res(a);
	for (--b; b; b >>= 1) {
		if (b & 1) res = res * a;
		a = a * a;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll k; cin >> n >> k;
	vvi a(n, vi(n));
	rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
	auto res = bpow(a, k);
	ll ans = 0;
	rep(i, 0, n) rep(j, 0, n) (ans += res[i][j]) %= M;
	cout << ans;
}