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
vector<int> g[N], h[N];
int nxt[N], indeg[N], lbl[N], num[N];
vector<int> bucket[N];

bool dfs(int u) {
	for (int v : h[u]) if (num[u] > num[v] || !dfs(v)) return 0;
	return 1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	for (int u = 1; u <= n; ++u) {
		int p; cin >> p;
		h[p].push_back(u);
	}
	rep(i, 0, k) { int x; cin >> x >> nxt[x]; ++indeg[nxt[x]]; }

	for (int u = 1; u <= n; ++u) {
		if (indeg[u]) continue;
		for (int v = u; v != 0; v = nxt[v]) {
			lbl[v] = u;
			bucket[u].push_back(v);
		}
	}

	for (int u = 0; u <= n; ++u) indeg[u] = 0;
	for (int u = 1; u <= n; ++u) {
		for (int v : h[u]) {
			int x = lbl[u], y = lbl[v];
			if (x == y) continue;
			g[x].push_back(y);
			++indeg[y];
		}
	}

	queue<int> q; vector<int> p;
	for (int u = 0; u <= n; ++u) if (indeg[u] == 0) q.push(u);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		p.push_back(u);
		for (int v : g[u]) if (--indeg[v] == 0) q.push(v);
	}

	for (int u = 1; u <= n; ++u) if (indeg[u]) return cout << 0, 0;
	int cur = 0;
	for (auto x : p) for (auto u : bucket[x]) num[u] = ++cur;
	if (!dfs(0)) return cout << 0, 0;
	for (auto x : p) for (auto u : bucket[x]) cout << u << ' ';
}