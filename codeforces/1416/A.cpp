;
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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 19;
int a[N], p[N], dist[N], ans[N];

void solve() {
	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	fill(p, p + n + 1, -1);
	fill(dist, dist + n + 1, -1);
	rep(i, 0, n) {
		ckmax(dist[a[i]], i - p[a[i]]);
		p[a[i]] = i;
	}
	for (int x = 0; x <= n; ++x) ckmax(dist[x], n - p[x]);
	fill(ans + 1, ans + n + 1, -1);
	int lst = n + 1;
	for (int x = 0; x <= n; ++x) {
		for (int i = dist[x]; i < lst; ++i) ans[i] = x;
		ckmin(lst, dist[x]);
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}