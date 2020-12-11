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

const int N = 1 << 9;
char g[N][N];
int d[N][N];
int n, m;

bool ok(int i, int j, int l) {
	if (l == 1) return true;
	if (j + 2 * l - 1 > m + 1)
		return false;
	rep(k, 0, l) if (d[i][j + k] < k + 1)
		return false;
	for (int k = l; k <= 2 * (l - 1); ++k)
		if (d[i][j + k] < -k + 2 * l - 1)
			return false;
	return true;
}


int solve() {
	cin >> n >> m;

	int res = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> g[i][j];
			if (g[i][j] != '*') d[i][j] = 0;
			else d[i][j] = d[i - 1][j] + 1;
		}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (g[i][j] != '*') { continue; }
			int l = 1, r = 2 * n;
			while (r - l > 1) {
				int m = (l + r) / 2;
				(ok(i, j, m) ? l : r) = m;
			}
			res += l;
			// ok(i, j, 2);
			// cerr << ok(i, j, 2) << ' ';
		}
		// cerr << '\n';
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}