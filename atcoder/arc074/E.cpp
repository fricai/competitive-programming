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

const int N = 300 + 5;
mint dp[N][N][N];
vector<pair<int, int>> v[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(i, 0, m) {
		int l, r, x; cin >> l >> r >> x;
		v[r].emplace_back(l, x);
	}

	dp[0][0][0] = 1;

	mint ans = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k <= n; ++k) {
				int r = max({i, j, k});

				bool works = true;
				for (auto [l, x] : v[r]) {
					int cnt = 0;
					cnt += l <= i;
					cnt += l <= j;
					cnt += l <= k;
					works &= cnt == x;
				}
				if (works) {
					if (r < n) {
						dp[r + 1][j][k] += dp[i][j][k];
						dp[i][r + 1][k] += dp[i][j][k];
						dp[i][j][r + 1] += dp[i][j][k];
					} else ans += dp[i][j][k];
				} else dp[i][j][k] = 0;
			}
		}
	}
	cout << ans.val();
}