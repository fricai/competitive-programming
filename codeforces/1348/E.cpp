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

const int N = 1 << 9;
const ll inf = 1e18;
bool dp[N][N];
int rem[N][N], n, k, a[N], b[N];

int sub(int a, int b) {
	int t = a - b;
	return t < 0 ? t + k : t;
}
int add(int a, int b) {
	int t = a + b;
	return k <= t ? t - k : t;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k; ll tot = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		tot += a[i] + b[i];
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		rep(j, 0, k) {
			rem[i][j] = k - 1;
			rep(l, 0, min(k, a[i] + 1)) {
				if (a[i] % k == l || k <= (a[i] - l) % k + b[i]) {
					if (dp[i - 1][sub(j, l)]) {
						dp[i][j] = true;
						ckmin(rem[i][j], rem[i - 1][sub(j, l)] + (b[i] + a[i] - l) % k);
					}
				}
			}
		}
	}

	ll ans = 0;
	rep(j, 0, k)
		if (dp[n][j])
			ckmax(ans, (tot - j) / k);
	cout << ans;
}