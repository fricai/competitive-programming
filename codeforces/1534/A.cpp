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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 64;
char g[N][N], h[N][N];

bool ok(int n, int m) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (g[i][j] != '.' && g[i][j] != h[i][j])
				return 0;
	return 1;
}

void solve() {
	int n, m; cin >> n >> m;
	rep(i, 0, n) cin >> g[i];
	
	char c[2] = {'W', 'R'};
	rep(b, 0, 2) {
		rep(i, 0, n)
			rep(j, 0, m)
				h[i][j] = c[(i + j + b) % 2];
		// rep(i, 0, n) {
		// 	rep(j, 0, m) cout << h[i][j];
		// 	cout << '\n';
		// }
		// cout << '\n';

		if (ok(n, m)) {
			cout << "YES\n";
			rep(i, 0, n) {
				rep(j, 0, m) cout << h[i][j];
				cout << '\n';
			}
			return;
		}
	}

	cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}