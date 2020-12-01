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

const int T = 1 << 20;
int f[T], g[T], X, d;

bool check(int n, int m, int x, int y) {
	if (x < 0 || x > n || y < 0 || y > m) return false;
	fill(g, g + n + m, 0);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			++g[abs(i - x) + abs(j - y)];
	rep(i, 0, n + m) if (f[i] != g[i]) return false;
	return true;
}

bool solve(int n, int m) {
	int x = X;
	int y = n + m - d - x;
	if (check(n, m, y, x)) swap(x, y);
	else if (!check(n, m, x, y)) return false;
	cout << n << ' ' << m << '\n' << x << ' ' << y << '\n';
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;

	d = -1;
	rep(i, 0, t) { int a; cin >> a; ++f[a]; ckmax(d, a); }
	rep(i, 1, T) if (f[i] != 4 * i) { X = i; break; }

	if (f[0] == 1 && d >= 0 && X > 0) {
		for (int n = 1; n * n <= t; ++n)
			if (t % n == 0 && solve(n, t / n))
				return 0;
	}
	cout << "-1";
}