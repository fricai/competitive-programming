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

const int N = 1 << 17, M = N + N;
vector<int> g[N];
bool dead[M];
int w[N], deg[N];
int a[M], b[M];
bool vis[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(i, 0, n) cin >> w[i];
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(e);
		g[v].push_back(e);
		a[e] = u; b[e] = v;
	}

	priority_queue<pair<int, int>> q;

	auto add = [&](int u) { q.push({w[u] - deg[u], u}); };
	rep(u, 0, n) {
		deg[u] = sz(g[u]);
		add(u);
	}

	vector<int> p;
	while (!q.empty()) {
		auto [del, u] = q.top(); q.pop();
		if (vis[u]) continue;
		if (del < 0) return cout << "DEAD", 0;
		vis[u] = 1;
		for (auto e : g[u]) {
			if (dead[e]) continue;
			--deg[a[e]]; --deg[b[e]];
			p.push_back(e);
		}
		for (auto e : g[u]) if (!dead[e]) add(a[e] ^ b[e] ^ u), dead[e] = 1;
	}
	if (sz(p) < m) return cout << "DEAD", 0;
	reverse(all(p));
	cout << "ALIVE" << '\n';
	for (auto x : p) cout << x + 1 << ' ';
}