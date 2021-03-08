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

const int N = 1 << 9;
int _f[N][N], g[N], a[N];

int f(int l, int r) {
	if (_f[l][r]) return _f[l][r];
	if (r - l == 1) return _f[l][r] = a[l];
	_f[l][r] = -1;
	rep(m, l + 1, r) {
		int L = f(l, m);
		int R = f(m, r);
		if (L == R && L > 0) _f[l][r] = L + 1;
	}
	return _f[l][r];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];

	fill_n(g + 1, n, N);
	rep(i, 0, n) 
		rep(j, i, n)
			if (f(i, j + 1) > 0)
				ckmin(g[j + 1], g[i] + 1);
	cout << g[n] << '\n';
}