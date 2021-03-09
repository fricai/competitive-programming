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

const int N = 1 << 17, P = 7;
const ll inf = 1e18;
ll dp[1 << P][N];
int a[N], s[P][N], ord[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p, k; cin >> n >> p >> k;
	rep(i, 0, n) cin >> a[i], ord[i] = i;
	rep(i, 0, n) rep(j, 0, p) cin >> s[j][i];
	sort(ord, ord + n, [&](int x, int y) {
		return a[x] > a[y];
	});

	rep(S, 1, 1 << p) dp[S][0] = -inf;
	dp[0][0] = 0;
	rep(i, 0, n) {
		rep(S, 0, 1 << p) dp[S][i + 1] = dp[S][i];
		rep(S, 0, 1 << p) {
			int c = p;
			rep(j, 0, p) {
				if (S >> j & 1) continue;
				ckmax(dp[S | 1 << j][i + 1], dp[S][i] + s[j][ord[i]]);
				--c;
			}
			if (i - c < k) ckmax(dp[S][i + 1], dp[S][i] + a[ord[i]]);
		}
	}
	cout << dp[(1 << p) - 1][n] << '\n';
}