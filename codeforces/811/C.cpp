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

const int N = 5005, A = N;
int dp[N], lst[A], fst[A], a[N];
bool vis[A];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) lst[a[i]] = i;
	for (int i = n; i > 0; --i) fst[a[i]] = i;

	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];

		int cur = 0;
		int mn_fst = i;

		fill(vis, vis + A, false);
		for (int j = i; j > 0; --j) {
			if (!vis[a[j]]) {
				if (lst[a[j]] > i) break;
				ckmin(mn_fst, fst[a[j]]);
				cur ^= a[j];
				vis[a[j]] = true;
			}
			if (j <= mn_fst) ckmax(dp[i], dp[j - 1] + cur);
		}
	}
	cout << dp[n];
}