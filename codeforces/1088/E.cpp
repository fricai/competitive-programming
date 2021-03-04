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

const int N = 3e5 + 20;
const ll inf = 1e18;
int a[N];
vector<int> g[N];
ll dp[N];
ll mean = -inf;
int k;

void get_mean(int u, int p) {
	dp[u] = a[u];
	for (int v : g[u]) {
		if (v == p) continue;
		get_mean(v, u);
		if (dp[v] > 0) dp[u] += dp[v];
	}
	ckmax(mean, dp[u]);
}

void get_k(int u, int p) {
	dp[u] = a[u];
	for (int v : g[u]) {
		if (v == p) continue;
		get_k(v, u);
		if (0 < dp[v] && dp[v] < mean) dp[u] += dp[v];
	}
	if (dp[u] == mean) ++k;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	get_mean(0, 0);
	get_k(0, 0);
	cout << mean * k << ' ' << k << '\n';
}