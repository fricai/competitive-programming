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
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		rep(i, 0, n) cin >> g[i];
		vector<pair<int, int>> z[2];
		z[g[1][0] - '0'].emplace_back(2, 1);
		z[g[0][1] - '0'].emplace_back(1, 2);
		z[1 - (g[n - 1][n - 2] - '0')].emplace_back(n, n - 1);
		z[1 - (g[n - 2][n - 1] - '0')].emplace_back(n - 1, n);
		auto ans = sz(z[0]) > sz(z[1]) ? z[1] : z[0];
		cout << sz(ans) << '\n';
		for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
	}
}