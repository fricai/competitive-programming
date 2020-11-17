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
vector<int> g[N];
int deg[N];
bool vis[N];

void solve() {
	int n, m, k; cin >> n >> m >> k;

	rep(u, 0, n) g[u].clear(), deg[u] = 0, vis[u] = 0;
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v); g[v].push_back(u);
		++deg[u]; ++deg[v];
	}
	rep(u, 0, n) sort(all(g[u]));

	if (1ll * k * (k - 1) / 2 > m) return void(cout << "-1\n");

	priority_queue<pair<int, int>> pq;
	rep(u, 0, n) pq.push({-deg[u], u});

	while (!pq.empty()) {
		auto [x, u] = pq.top(); pq.pop();

		if (vis[u]) continue;
		x = -x;
		vis[u] = true;

		g[u].erase(stable_partition(all(g[u]), [&](int x) { return !vis[x]; }), end(g[u]));
		if (x == k - 1) {
			if ([&]() {
				for (int v : g[u])
					for (int x : g[u])
						if (x != v && !binary_search(all(g[v]), x)) return false;
				return true;
			}()) {
				cout << "2\n" << u + 1;
				for (int v : g[u]) cout << ' ' << v + 1;
				cout << '\n';
				return;
			}
		}
		if (x < k) {
			for (int v : g[u]) pq.push({-(--deg[v]), v});
			continue;
		}
		vector<int> res = {u};
		while (!pq.empty()) {
			auto [_, v] = pq.top(); pq.pop();
			if (vis[v]) continue;
			vis[v] = true;
			res.push_back(v);
		}
		cout << 1 << ' ' << sz(res) << '\n';
		for (int x : res) cout << x + 1 << ' ';
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