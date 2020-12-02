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

const int N = 1 << 6, M = 1e9 + 7;
int dp[2][2][2][2];
int c[N], q[N];

template<class T> void add(T &a, const T& b) { a += b; if (M <= a) a -= M; }
int mult(const int &a, ll b) { return a * b % M; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; short p; cin >> n >> p;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	q[0] = 1; rep(i, 1, N) { q[i] = (q[i - 1] << 1) % M; }

	int res = 0;
	dp[0][0][0][0] = 1;
	for (int i = 1, cur = 1; i <= n; ++i, cur ^= 1) {
		rep(w, 0, 2) {
			rep(b, 0, 2) {
				rep(parity, 0, 2) {
					auto &x = dp[cur][w][b][parity]; x = 0;
					if (c[i] != 1) {
						add(x, mult(dp[!cur][w][b][parity], w ? q[i - 2] : 0));
						if (b) add(x, mult(dp[!cur][w][0][!parity] + dp[!cur][w][1][!parity], w ? q[i - 2] : q[i - 1]));
					}
					if (c[i] != 0) {
						add(x, mult(dp[!cur][w][b][parity], b ? q[i - 2] : 0));
						if (w) add(x, mult(dp[!cur][0][b][!parity] + dp[!cur][1][b][!parity], b ? q[i - 2] : q[i - 1]));
					}
					if (i == n && p == parity) add(res, x);
				}
			}
		}
	}
	cout << res;
}