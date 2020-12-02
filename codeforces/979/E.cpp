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
int dp[N][N][N][N];
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
		for (int w1 = 0; w1 <= i; ++w1) {
			for (int b1 = 0; w1 + b1 <= i; ++b1) {
				for (int w0 = 0; w1 + b1 + w0 <= i; ++w0) {
					int b0 = i - w1 - b1 - w0;
					auto &x = dp[w1][b1][w0][b0];
					if (c[i] != 1) {
						if (b0) add(x, mult(dp[w1][b1][w0][b0 - 1], w1 ? q[i - 2] : 0));
						if (b1) add(x, mult(dp[w1][b1 - 1][w0][b0], w1 ? q[i - 2] : q[i - 1]));
					}
					if (c[i] != 0) {
						if (w0) add(x, mult(dp[w1][b1][w0 - 1][b0], b1 ? q[i - 2] : 0));
						if (w1) add(x, mult(dp[w1 - 1][b1][w0][b0], b1 ? q[i - 2] : q[i - 1]));
					}
					if (i == n && p == ((b1 + w1) & 1)) add(res, x);
				}
			}	
		}
	}
	cout << res;
}