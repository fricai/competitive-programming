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
const ll inf = 1e18;
vector<int> g[N];
ll a[N];
ll dp[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	
	rep(i, 0, n) cin >> a[i];
	rep(e, 0, m) {
		int x, y; cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
	}

	ll ans = -inf;
	per(u, 0, n) {
		dp[u] = -inf;
		for (int v : g[u]) ckmax(dp[u], max(a[v], dp[v]));
		ckmax(ans, dp[u] - a[u]);
	}
	cout << ans;
}