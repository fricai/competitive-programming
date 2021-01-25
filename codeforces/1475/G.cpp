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

const int N = 1 << 18;
int cnt[N], dp[N], a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		rep(i, 0, n) cin >> a[i];

		fill(cnt, cnt + N, 0);
		
		rep(i, 0, n) ++cnt[a[i]];
		rep(x, 1, N) dp[x] = cnt[x];

		int ans = 0;
		for (int x = 1; x < N; ++x) {
			for (int y = x + x; y < N; y += x)
				ckmax(dp[y], dp[x] + cnt[y]);
			ckmax(ans, dp[x]);
		}
		
		cout << n - ans << '\n';
	}
}