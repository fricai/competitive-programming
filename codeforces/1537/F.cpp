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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
vector<int> g[N];
short col[N];

bool bipartite(int u, bool b) {
	if (col[u] < 0) col[u] = b;
	else return col[u] == b;
	for (int v : g[u])
		if (!bipartite(v, !b))
			return 0;
	return 1;
}

bool solve() {
	int n, m; cin >> n >> m;
	
	vector<int> v(n);

	bool parity = 0;
	for (auto &x : v) cin >> x;
	for (auto &x : v) {
		int y; cin >> y;
		x -= y;
		parity ^= x & 1;
	}
	
	rep(i, 0, n) g[i].clear();
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if (parity) return 0;
	fill_n(col, n, -1);
	
	if (!bipartite(0, 0)) return 1;
	
	ll sum = 0;
	rep(u, 0, n) {
		assert(col[u] != -1);
		if (col[u]) sum += v[u];
		else sum -= v[u];
	}
	return sum == 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}