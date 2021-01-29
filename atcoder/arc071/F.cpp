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

const int N = 1 << 20, M = 1e9 + 7;
using mint = atcoder::static_modint<M>;
int a[N];
int ans = 0;
void brute(int i, int n) {
	if (i != n) {
		for (int j = 1; j <= n; ++j) {
			a[i] = j;
			brute(i + 1, n);
		}
	} else {
		bool works = true;
		// if (n != *max_element(a, a + n)) return;
		rep(i, 0, n) {
			rep(j, i + 1, min(n, i + a[i] + 1))
				if (a[i + 1] != a[j]) {
					works = false;
					break;
				}
			if (!works) break;
		}
		// if (works) {
		// 	rep(i, 0, n) cerr << a[i] << ' ';
		// 	cerr << '\n';
		// }
		ans += works;
	}
}

mint dp[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	// brute(0, n);
	// cout << ans << '\n';

	mint sum = 0;
	dp[0] = 0;
	dp[1] = n;
	dp[2] = dp[1] * dp[1];
	mint z = n - 1; z *= z; z += n;
	for (int i = 3; i <= n; ++i) {
		sum += dp[i - 3];
		dp[i] = dp[i - 1] + sum;
		--z;
		dp[i] += z;
	}
	cout << dp[n].val();
}