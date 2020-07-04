#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 400;
int n, m;
int g[N][N], h[N][N];
vector<pair<int, int>> f[5];

bool solve() {
	rep(i, 0, n) rep(j, 0, m) cin >> g[i][j];
	rep(i, 0, n) rep(j, 0, m) h[i][j] = 4;
	rep(i, 0, n) h[i][0] = h[i][m - 1] = 3;
	rep(j, 0, m) h[0][j] = h[n - 1][j] = 3;
	h[0][0] = h[0][m - 1] = h[n - 1][0] = h[n - 1][m - 1] = 2;
	rep(i, 0, n) rep(j, 0, m) if (g[i][j] > h[i][j]) return false;
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		bool b = solve();
		if (!b) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		rep(i, 0, n) {
			rep(j, 0, m)
				cout << h[i][j] << ' ';
			cout << '\n';
		}
	}
}