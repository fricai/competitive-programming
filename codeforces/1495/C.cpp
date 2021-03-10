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
int n, m;
bool g[N][N];
bool res[N][N];

void solve() {
	rep(i, 0, n) {
		rep(j, 0, m) {
			char c; cin >> c;
			g[i][j] = c == 'X';
			// g[i][j] = 0;
		}
	}

	rep(i, 0, n) rep(j, 0, m) res[i][j] = g[i][j];

	for (int i = n % 3 == 0; i < n; i += 3)
		rep(j, 0, m) res[i][j] = 1;
	for (int i = n % 3 == 0; i + 2 < n; i += 3) {
		// assert(i + 2 < n);
		int k = m;
		rep(j, 0, m) if (g[i + 1][j]) k = j;
		rep(j, 0, m) if (g[i + 2][j]) k = j;
		if (k == m) k = 0;
		res[i + 1][k] = res[i + 2][k] = 1;
		if (k) assert(!res[i + 1][k - 1] && !res[i + 2][k - 1]);
		if (k + 1 < m) assert(!res[i + 1][k + 1] && !res[i + 2][k + 1]);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		cin >> n >> m;

		solve();

		// cerr << '\n';
		rep(i, 0, n) {
			rep(j, 0, m) cout << (res[i][j] ? 'X' : '.');
			cout << '\n';
		}
	}
}