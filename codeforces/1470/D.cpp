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

const int N = 1 << 19;
vector<int> g[N];
bool vis[N];

void solve() {
	int n, m; cin >> n >> m;

	for (int u = 1; u <= n; ++u) g[u].clear(), vis[u] = 0;

	rep(e, 0, m) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	queue<int> q; q.push(1);

	vector<int> res;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (!vis[u]) {
			res.push_back(u);
			vis[u] = true;
			for (int v : g[u]) {
				if (vis[v]) continue;
				vis[v] = true;
				for (int w : g[v]) if (!vis[w]) q.push(w);
			}
		}
	}
	
	for (int u = 1; u <= n; ++u) if (!vis[u]) return void(cout << "NO\n");
	cout << "YES\n" << sz(res) << '\n';
	for (int v : res) cout << v << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}