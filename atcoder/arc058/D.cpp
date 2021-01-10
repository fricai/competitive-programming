#include <bits/stdc++.h>

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

const int M = 1e9 + 7, N = 1 << 18;
using ull = unsigned long long;
ull modmul(ull a, ull b) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

int inv[N], f[N], fi[N];
int nCr(int n, int k) { return modmul(f[n], modmul(fi[k], fi[n - k])); }


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = f[1] = fi[0] = fi[1] = inv[1] = 1;
	rep(i, 2, N) {
		inv[i] = M - modmul(M / i, inv[M % i]);
		f[i] = modmul(i, f[i - 1]);
		fi[i] = modmul(inv[i], fi[i - 1]);
	}

	int h, w, a, b; cin >> h >> w >> a >> b;

	int ans = 0;
	for (int x = 0; x < h - a; ++x) {
		ans += modmul(nCr(b + x - 1, b - 1), nCr(w - b  - 1 + h - x - 1, w - b - 1));
		if (M <= ans) ans -= M;
	}
	cout << ans;
}