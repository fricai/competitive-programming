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
vector<int> d[N];
int cnt[N], dp[N], a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(i, 1, N) for (int j = 2 * i; j < N; j += i) d[j].push_back(i);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		rep(i, 0, n) cin >> a[i];

		fill(cnt, cnt + N, 0);
		fill(dp, dp + N, 0);

		rep(i, 0, n) ++cnt[a[i]];
		
		int ans = 0;
		for (int x = 1; x < N; ++x) {
			dp[x] = cnt[x];
			for (int y : d[x])
				ckmax(dp[x], dp[y] + cnt[x]);
			ckmax(ans, dp[x]);
		}
		
		cout << n - ans << '\n';
	}
}