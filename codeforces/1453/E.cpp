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
vector<int> g[N];

int ans;
int dfs(int u, int p) {
	if (u && sz(g[u]) == 1) return 1;
	vector<int> opt;
	for (int v : g[u]) if (v != p) opt.push_back(dfs(v, u));
	sort(rall(opt));
	if (sz(opt) > 1) {
		if (u) ckmax(ans, opt[0] + 1);
		else ckmax(ans, max(opt[0], opt[1] + 1));
	} else ckmax(ans, opt[0]);
	return opt.back() + 1;
}

void solve() {
	int n; cin >> n;
	rep(u, 0, n) g[u].clear();
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans = 0; dfs(0, 0);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}