#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define eb(x...) emplace_back(x)
#define ff first
#define ss second

using ll = int64_t;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

using pll = pair<ll, ll>;

const int N = 3001;
int a[N];
pll dp[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	per(l, 0, n) {
		dp[l][l] = {a[l], 0};
		rep(r, l + 1, n) {
			auto tl = dp[l + 1][r]; swap(tl.ff, tl.ss);
			auto tr = dp[l][r - 1]; swap(tr.ff, tr.ss);
			tl.ff += a[l]; tr.ff += a[r];
			dp[l][r] = (tl.ff - tl.ss > tr.ff - tr.ss ? tl : tr);
		}
	}
	cout << dp[0][n - 1].ff - dp[0][n - 1].ss;
}