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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 11, A = 26;
char g[N][N];
int ff[N][N], fb[N][N], bb[N][N], bf[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(i, 0, n) cin >> g[i];
	rep(i, 1, n)
		rep(j, 1, m)
			if (g[i][j] == g[i - 1][j] && g[i][j] == g[i][j - 1])
				ff[i][j] = 1 + min(ff[i - 1][j], ff[i][j - 1]);
	rep(i, 1, n)
		per(j, 0, m - 1)
			if (g[i][j] == g[i - 1][j] && g[i][j] == g[i][j + 1])
				fb[i][j] = 1 + min(fb[i - 1][j], fb[i][j + 1]);
	per(i, 0, n - 1)
		per(j, 0, m - 1)
			if (g[i][j] == g[i + 1][j] && g[i][j] == g[i][j + 1])
				bb[i][j] = 1 + min(bb[i + 1][j], bb[i][j + 1]);
	per(i, 0, n - 1)
		rep(j, 1, m)
			if (g[i][j] == g[i + 1][j] && g[i][j] == g[i][j - 1])
				bf[i][j] = 1 + min(bf[i + 1][j], bf[i][j - 1]);
	ll ans = 0;
	rep(i, 0, n) {
		rep(j, 0, m) {
			int z = min({bb[i][j], ff[i][j], bf[i][j], fb[i][j]});
			// cerr << z;
			ans += 1 + z;
		}
		// cerr << '\n';
	}
	cout << ans;
}