#include <bits/stdc++.h>
#include <atcoder/modint>

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

const int M = 1e9 + 7;
using mint = atcoder::static_modint<M>;

const int N = 1 << 10;
mint f[N], fi[N], inv[N], dp[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = f[1] = fi[0] = fi[1] = inv[1] = 1;
	rep(i, 2, N) {
		inv[i] = - M / i * inv[M % i];
		f[i] = i * f[i - 1];
		fi[i] = inv[i] * fi[i - 1];
	}

	int n, a, b, c, d; cin >> n >> a >> b >> c >> d;

	// dp[i][j] = number of ways to divide i such that largest group has size <= j and partition is valid

	for (int r = 0; r * a <= n; ++r)
		if (!r || (c <= r && r <= d))
			dp[r * a][a] = f[r * a] * fi[r] * fi[a].pow(r);
	for (int i = 0; i <= n; ++i)
		for (int j = a + 1; j <= b; ++j)
			for (int r = 0; i - r * j >= 0; ++r)
				if (!r || (c <= r && r <= d))
					dp[i][j] += dp[i - r * j][j - 1] * f[i] * fi[i - r * j] * fi[r] * fi[j].pow(r);
	cout << dp[n][b].val();
}