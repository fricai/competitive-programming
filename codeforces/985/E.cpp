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

const int N = 1 << 19;
bool _dp[2 * N];
int a[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, d; cin >> n >> k >> d;
	rep(i, 0, n) cin >> a[i + 1];
	sort(a + 1, a + n + 1);
	bool* dp = _dp + N;
	dp[0] = 1;
	for (int i = 1, j = 0, cnt = 0; i <= n; ++i) {
		while (j <= i - k && a[i] - a[j + 1] > d) cnt -= dp[j++];
		cnt += dp[i - k];
		dp[i] = !!cnt;
	}
	cout << (dp[n] ? "YES" : "NO");
}