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

const int N = 1 << 17;
vector<int> g[N], mn[N];
int deg[N];
bool vis[N];

void solve() {
	int n, m, k; cin >> n >> m >> k;

	for (int u = 1; u <= n; ++u) g[u].clear();
	rep(e, 0, m) {
		int u, v; cin >> u >> v;
		g[u].push_back(v); g[v].push_back(u);
	}

	if (1ll * k * (k - 1) / 2 > m) return void(cout << "-1\n");

	rep(u, 0, n) mn[u].clear();
	for (int u = 1; u <= n; ++u) {
		vis[u] = 0;
		deg[u] = sz(g[u]);
		mn[deg[u]].push_back(u);
		sort(all(g[u]));
	}

	for (int x = 0; x < n; x = mn[x].empty() ? x + 1 : x) {
		if (mn[x].empty()) continue;

		int u = mn[x].back(); mn[x].pop_back();

		if (vis[u]) continue;

		vis[u] = true;
		g[u].erase(stable_partition(all(g[u]), [&](int x) { return !vis[x]; }), end(g[u]));

		if (x == k - 1) {
			if ([&]() {
				for (int v : g[u])
					for (int x : g[u])
						if (x != v && !binary_search(all(g[v]), x)) return false;
				return true;
			}()) {
				cout << "2\n" << u;
				for (int v : g[u]) cout << ' ' << v;
				cout << '\n';
				return;
			}
		}

		if (x < k) {
			for (int v : g[u]) {
				--deg[v];
				mn[deg[v]].push_back(v);
				ckmin(x, deg[v]);
			}
			continue;
		}

		vector<int> res = {u};
		rep(i, 0, n) for (int v : mn[i]) if (!vis[v]) res.push_back(v), vis[v] = true;
		cout << 1 << ' ' << sz(res) << '\n';
		for (int x : res) cout << x << ' ';
		cout << '\n';
		return;
	}

	cout << "-1\n";
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--) solve();
}