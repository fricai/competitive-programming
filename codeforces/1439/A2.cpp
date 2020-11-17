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

const int N = 1 << 7;
bool g[N][N];

vector<vector<pair<int, int>>> op;

void stuff(vector<pair<int, int>> z) {
	op.eb(z);
	for (auto [x, y] : z) g[x][y] ^= 1;
}

int n, m;

void f(int n, int m) {
	if (n > 2) {
		rep(j, 0, m) if (g[n - 1][j]) stuff({{n - 1, j}, {n - 2, j}, {n - 2, abs(j - 1)}});
		return f(n - 1, m);
	}
	if (m > 2) {
		rep(i, 0, n) if (g[i][m - 1]) stuff({{i, m - 1}, {i, m - 2}, {abs(i - 1), m - 2}});
		return f(n, m - 1);
	}

	vector<pair<int, int>> ye, ne;
	rep(x, 0, 2)
		rep(y, 0, 2)
			if (g[x][y]) ye.eb(x, y);
			else ne.eb(x, y);
	if (sz(ye) == 1) {	
		auto [a, b] = ye[0];
		int s = a + 1, t = b + 1;
		if (s > 1) s = a - 1;
		if (t > 1) t = b - 1;
		stuff({{a, b}, {s, b}, {a, t}});
		stuff({{a, b}, {a, t}, {s, t}});
		stuff({{a, b}, {s, t}, {s, b}});
		return;
	}
	if (sz(ye) == 2) return ye.eb(ne[0]), stuff(ye), f(2, 2);
	if (sz(ye) == 3) return stuff(ye);
	if (sz(ye) == 4) return stuff({{0, 0}, {1, 0}, {0, 1}}), f(2, 2);
}

void solve() {
	op.clear();

	cin >> n >> m;
	rep(i, 0, n) {
		rep(j, 0, m) {
			char c; cin >> c;
			g[i][j] = c == '1';
		}
	}
	f(n, m);
	rep(i, 0, n)
		rep(j, 0, m)
			assert(!g[i][j]);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		solve();
		cout << sz(op) << '\n';
		for (auto v : op) {
			for (auto [x, y] : v) cout << x + 1 << ' ' << y + 1 << ' ';
			cout << '\n';
		}
	}
}