#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(x, v) for (auto &x : v)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

const int B = 18, N = 1 << (B - 1), K = 10; int k = K;
vector<int> operator+(const vector<int> &a, const vector<int> &b) {
	vector<int> v(sz(a) + sz(b));
	merge(all(a), all(b), begin(v));
	if (k < sz(v)) v.resize(k); return v;
}

vector<int> g[N], z[N][B + 1]; int a[N][B + 1], d[N];
void dfs(int u, int p) {
	a[u][0] = p; d[u] = d[p] + 1;
	trav(v, g[u]) if (v != p) dfs(v, u);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q; cin >> n >> m >> q;
	rep(i, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v); g[v].push_back(u);
	}

	rep(i, 0, m) {
		int x; cin >> x; --x;
		if (sz(z[x][0]) < K) z[x][0].push_back(i + 1);
	}

	a[n][0] = n; dfs(0, n);
	rep(j, 0, B - 1)
		rep(u, 0, n + 1)
			a[u][j + 1] = a[a[u][j]][j],
			z[u][j + 1] = z[a[u][j]][j] + z[u][j];

	while (q--) {
		int u, v; cin >> u >> v >> k; --u; --v;
		vector<int> x; if (d[u] < d[v]) swap(u, v);
		for (int j = B; j--;)
			if (d[v] <= d[a[u][j]])
				x = x + z[u][j], u = a[u][j];
		if (u != v) {
			for (int j = B; j--;)
				if (a[v][j] != a[u][j])
					x = x + z[u][j] + z[v][j],
					u = a[u][j], v = a[v][j];
			x = x + z[u][1] + z[v][0];
		} else x = x + z[u][0];
		cout << sz(x); trav(v, x) cout << ' ' << v; cout << '\n';
	}
}