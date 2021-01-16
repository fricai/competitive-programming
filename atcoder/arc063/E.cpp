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

const int N = 1 << 17;
int val[N], d[N], node[N];
vector<int> g[N];
bool marked[N];
int in[N], timer = 0;

int root = -1;

void init(int u) {
	for (int v : g[u]) {
		g[v].erase(find(all(g[v]), u));
		d[v] = d[u] + 1;
		init(v);
	}
}

const int inf = 1e9;
int lo[N], hi[N];

void dfs(int u) {
	if (val[u] < 0) { lo[u] = -inf; hi[u] = inf; }
	else lo[u] = hi[u] = val[u];
	for (int v : g[u]) {
		dfs(v);
		ckmax(lo[u], lo[v] - 1);
		ckmin(hi[u], hi[v] + 1);
	}
}

void dfs2(int u) {
	for (int v : g[u]) {
		if (lo[v] <= val[u] - 1 && val[u] - 1 <= hi[v]) val[v] = val[u] - 1;
		else val[v] = val[u] + 1;
		dfs2(v);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);	
	}

	fill(val, val + n, -1);

	int k; cin >> k;
	rep(i, 0, k) cin >> root >> val[--root];

	init(root);

	rep(u, 0, n) {
		if (val[u] < 0) continue;
		if ((val[u] ^ val[root] ^ d[u]) & 1) return cout << "No", 0;
	}
	dfs(root);
	rep(u, 0, n) if (hi[u] < lo[u]) return cout << "No", 0;
	
	dfs2(root);

	cerr << root << '\n';
	cout << "Yes\n";
	rep(u, 0, n) cout << val[u] << '\n';
}