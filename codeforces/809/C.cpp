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


const int B = 31, M = 1e9 + 7;

template<class T> void add(T &x, int y) { x += y; if (M <= x) x -= M; }
template<class T> void sub(T &x, int y) { x -= y; if (x < 0) x += M; }

int dp[B + 1][2][2][2], f[B + 1][2][2][2];

void add(int &x, int y) { x += y; if (M <= x) x -= M; }
void sub(int &x, int y) { x -= y; if (x < 0) x += M; }

int g(int x, int y, int k) {
	rep(i, 0, B) rep(a, 0, 2) rep(b, 0, 2) rep(c, 0, 2) dp[i][a][b][c] = f[i][a][b][c] = 0;
	f[B][0][0][0] = 1;
	per(z, 0, B) {
		int u = x >> z & 1, v = y >> z & 1, w = k >> z & 1;
		for (auto a : {0, 1}) {
			for (auto b : {0, 1}) {
				for (auto c : {0, 1}) {
					// a = 0 if current is equal to x
					for (auto p : {0, 1}) {
						for (auto q : {0, 1}) {
							auto r = p ^ q;
							if ((!a && p > u) || (!b && q > v) || (!c && r > w)) continue;
							auto i = a || p != u, j = b || q != v, k = c || r != w;
							add(dp[z][i][j][k], dp[z + 1][a][b][c]);
							if (r) add(dp[z][i][j][k], (ll(f[z + 1][a][b][c]) << z) % M);
							add(f[z][i][j][k], f[z + 1][a][b][c]);
						}
					}
				}
			}
		}
	}
	return (dp[0][1][1][1] + f[0][1][1][1]) % M;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
		--a; --b;
		int ans = 0;
		add(ans, g(c, d, k));
		sub(ans, g(a, d, k));
		sub(ans, g(c, b, k));
		add(ans, g(a, b, k));
		cout << ans << '\n';
	}
}