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

const int N = 300 + 10;
vector<int> g[N], h[N];
ll a[N], b[N], val, sum, p[N], deg[N];
bool vis[N], vis1[N], dead[N];
vector<int> cmp;

void dfs_init(int u) {
	vis1[u] = 1;
	sum += a[u] - b[u];
	cmp.push_back(u);
	for (int v : g[u]) {
		if (vis1[v]) continue;
		p[v] = u;
		++deg[u];
		dfs_init(v);
	}
}

vector<tuple<int, int, int>> op;

void do_op(int u, int v, int d) { // send d, u -> v 
	if (d == 0) return;
	assert(d > 0);
	a[u] -= d; a[v] += d;
	assert(0 <= a[u]); assert(a[v] <= val);
	op.emplace_back(u, v, d);
}

void fill_up(int u) {
	vis[u] = 1;
	for (int v : g[u]) {
		if (vis[v] || dead[v]) continue;
		fill_up(v);
		if (a[u] + a[v] <= val) do_op(v, u, a[v]);
		else do_op(v, u, val - a[u]);
	}
}

void empty_it(int u) {
	vis[u] = 1;
	for (int v : g[u]) {
		if (vis[v] || dead[v]) continue;
		empty_it(v);
		if (a[u] + a[v] <= val) do_op(u, v, a[u]);
		else do_op(u, v, val - a[v]);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> val >> m;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	rep(u, 0, n) {
		if (vis1[u]) continue;
		sum = 0; cmp.clear();
		p[u] = -1; dfs_init(u);

		if (sum != 0) return cout << "NO", 0;

		queue<int> q;
		for (auto x : cmp) if (deg[x] == 0) q.push(x);
		while (!q.empty()) {
			auto v = q.front(); q.pop();

			assert(!dead[v]);

			dead[v] = 1;
			
			if (p[v] != -1 && --deg[p[v]] == 0) q.push(p[v]);

			if (a[v] == b[v]) continue;

			assert(p[v] != -1);

			fill_n(vis, n, 0);
			if (a[v] < b[v]) {
				fill_up(p[v]);
				do_op(p[v], v, b[v] - a[v]);
			} else {
				empty_it(p[v]);
				do_op(v, p[v], a[v] - b[v]);
			}
		}
	}

	cout << sz(op) << '\n';
	for (auto [x, y, d] : op) cout << x + 1 << ' ' << y + 1 << ' ' << d << '\n';
}