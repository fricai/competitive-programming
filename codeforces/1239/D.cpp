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

const int N = 1 << 20;

vector<int> g[2 * N], gr[2 * N];
vector<int> ord;
bool vis[2 * N];

void dfs1(int u) {
	vis[u] = 1;
	for (auto v : g[u]) if (!vis[v]) dfs1(v);
	ord.push_back(u);
}

vector<int> cmp;
void dfs2(int u) {
	vis[u] = true;
	cmp.push_back(u);
	for (auto v : gr[u]) if (!vis[v]) dfs2(v);
}

void solve() {
	int n, m; cin >> n >> m;

	rep(u, 0, 2 * n) g[u].clear(), gr[u].clear(), vis[u] = false;

	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		v += n;
		if (v - u != n) {
			g[u].push_back(v);
			gr[v].push_back(u);
		} else {
			g[v].push_back(u);
			gr[u].push_back(v);
		}
	}

	ord.clear();
	rep(u, 0, 2 * n) if (!vis[u]) dfs1(u);
	
	reverse(all(ord));
	fill_n(vis, 2 * n, false);

	int cnt = 0;
	for (auto u : ord)
		if (!vis[u]) {
			++cnt;
			if (cnt == 2) break;
			cmp.clear(); dfs2(u);
		}

	if (n == 1 || cnt <= 1) {
		cout << "No\n";
		return;
	}

	vector<int> R;
	vector<bool> ok(n, true);

	int j = n, p = 0;
	for (auto v : cmp)
		if (v >= n)
			R.push_back(v - n), ok[v - n] = false, --j, ++p;

	cout << "Yes\n";
	cout << j << ' ' << p << '\n';

	rep(u, 0, n) if (ok[u]) cout << u + 1 << ' ';
	cout << '\n';
	
	for (auto x : R) cout << x + 1 << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}