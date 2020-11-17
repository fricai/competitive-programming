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
		for (int j = 1; j <= m; ++j) if (g[n][j]) stuff({{n, j}, {n - 1, j}, {n - 1, j != 1 ? j - 1 : 2}});
		return f(n - 1, m);
	}

	if (m > 2) {
		for (int i = 1; i <= m; ++i) if (g[i][m]) stuff({{i, m}, {i, m - 1}, {i != 1 ? i - 1 : 2, m - 1}});
		return f(n, m - 1);
	}

	vector<pair<int, int>> ye, ne;
	for (int x : {1, 2})
		for (int y : {1, 2})
			if (g[x][y]) ye.eb(x, y);
			else ne.eb(x, y);
	if (ye.empty()) return;
	if (sz(ye) == 2) return ye.eb(ne[0]), stuff(ye), f(2, 2);
	if (sz(ye) == 3) return stuff(ye);
	if (sz(ye) == 4) return stuff({{1, 1}, {2, 1}, {1, 2}}), f(2, 2);
	auto [a, b] = ye[0];
	int s = a - 1, t = b - 1;
	if (s <= 0) s = 2;
	if (t <= 0) t = 2;
	stuff({{a, b}, {s, b}, {a, t}});
	stuff({{a, b}, {a, t}, {s, t}});
	stuff({{a, b}, {s, t}, {s, b}});
}

void solve() {
	op.clear();
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char c; cin >> c;
			g[i][j] = c != '0';
		}
	}
	f(n, m);
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		solve();
		cout << sz(op) << '\n';
		for (auto v : op) {
			for (auto [x, y] : v) cout << x << ' ' << y << ' ';
			cout << '\n';
		}
	}
}