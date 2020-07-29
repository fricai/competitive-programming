#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 17, B = 8;
const ll inf = 1e18;
ll a[N], dp[N][B];

int n, k, z;
ll f(int i, int j, int k, bool b) {
	if (!k) return a[i];
	if (b) return a[i] + f(i + 1, j, k - 1, 0);
	if (0 <= dp[i][j]) return dp[i][j];
	if (i && j) ckmax(dp[i][j], a[i] + f(i - 1, j - 1, k - 1, 1));
	if (i < n - 1) ckmax(dp[i][j], a[i] + f(i + 1, j, k - 1, 0));
	return dp[i][j];
}

ll solve() {
	cin >> n >> k >> z;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) rep(j, 0, z + 1) dp[i][j] = -1;
	return f(0, z, k, 0);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}