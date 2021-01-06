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

const int B = 500, N = 1 << 17, M = 1 << 17;
vector<int> g[N], h[N];
int indeg[N], outdeg[N], ord[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(e, 0, m) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	
	for (int u = 1; u <= n; ++u) ord[u] = u;

	for (int u = 1; u <= n; ++u)
		for (int v : g[u])
			if (v < u) ++outdeg[u];
			else {
				++indeg[u];
				h[u].push_back(v);
			}

	ll init = 0;
	for (int u = 1; u <= n; ++u)
		init += 1ll * indeg[u] * outdeg[u];

	cout << init << '\n';

	int q; cin >> q;
	for (int t = n + 1; t <= q + n; ++t) {
		int u; cin >> u;
		init -= 1ll * indeg[u] * outdeg[u];
		for (int v : h[u]) {
			init -= 1ll * indeg[v] * outdeg[v];
			h[v].push_back(u);
			++indeg[v]; --outdeg[v];
			init += 1ll * indeg[v] * outdeg[v];
		}
		outdeg[u] += indeg[u];
		indeg[u] = 0;
		h[u].clear();
		ord[u] = t;
		cout << init << '\n';
	}
}