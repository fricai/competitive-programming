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

const int N = 300 + 10, B = 9;
const ll inf = 1e8;

int l[N], c[N];
ll dp[N][1 << B];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int g = 0;
	rep(i, 0, n) cin >> l[i], g = gcd(g, l[i]);
	rep(i, 0, n) cin >> c[i];
	if (g > 1) return cout << "-1\n", 0;

	ll ans = inf;
	rep(i, 0, n) {
		swap(c[0], c[i]);
		swap(l[0], l[i]);
		
		int x = l[0];
		vector<int> p;
		for (int d = 2; d * d <= x; ++d) {
			if (x % d) continue;
			while (x % d == 0) x /= d;
			p.push_back(d);
		}
		if (x != 1) p.push_back(x);
		int k = sz(p);

		rep(i, 0, n) rep(S, 0, 1 << k) dp[i][S] = inf;
		dp[0][0] = c[0];
		
		rep(j, 1, n) {
			rep(S, 0, 1 << k) {
				int T = S;
				rep(r, 0, k) if (l[j] % p[r]) T |= 1 << r;
				ckmin(dp[j][S], dp[j - 1][S]);
				ckmin(dp[j][T], dp[j - 1][S] + c[j]);
			}
		}
		swap(c[0], c[i]);
		swap(l[0], l[i]);
		ckmin(ans, dp[n - 1][(1 << k) - 1]);
	}
	cout << ans;
}