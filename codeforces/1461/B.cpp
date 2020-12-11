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

int solve() {
	int n, m; cin >> n >> m;
	int res = 0;

	rep(i, 0, n) cin >> g[i];

	rep(j, 0, m) d[n][j] = 0;
	per(i, 0, n) {
		rep(j, 0, m) {
			if (g[i][j] != '*') {
				d[i][j] = 0;
				continue;
			}
			d[i][j] = 1 + (j > 0 && j < m - 1 ? min({d[i + 1][j - 1], d[i + 1][j], d[i + 1][j + 1]}) : 0); 
			res += d[i][j];
		}
	}	
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}