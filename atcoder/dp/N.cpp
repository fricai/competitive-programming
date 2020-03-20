#include <algorithm>
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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int a[n]; rep(i, 0, n) cin >> a[i];
	ll f[n][n];
	per(l, 0, n) {
		f[l][l] = 0;
		rep(r, l + 1, n) {
			f[l][r] = f[l + 1][r];
			rep(m, l + 1, r) ckmin(f[l][r], f[l][m] + f[m + 1][r]);
			rep(i, l, r + 1) f[l][r] += a[i];
		}
	}
	cout << f[0][n - 1];
}