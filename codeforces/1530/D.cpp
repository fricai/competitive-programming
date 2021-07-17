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

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x, --x;
	vector<int> col(n), indeg(n);
	
	for (auto x : a)
		++indeg[x];

	/*
		0 -> unvisited
		1 -> active
		2 -> visited, part of chain
		3 -> visited, part of cycle
	*/

	// start chain at nodes with indegree 0,

	vector<vector<int>> chains, cycles;
	
	for (int u = 0; u < n; ++u) {
		if (indeg[u] != 0) continue;
		assert(col[u] == 0);
		
		int v = u;

		// vector<int> cur;
		
		while (col[v] == 0) {
			// cur.push_back(v);
			col[v] = 1;
			v = a[v];
		}
		
		chains.push_back({});
		for (int w = u; w != v; w = a[w])
			chains.back().push_back(w),
			col[w] = 2;

		if (col[v] == 1) {
			cycles.push_back({});
			while (col[v] == 1) {
				cycles.back().push_back(v);
				col[v] = 3;
				v = a[v];
			}
		}
		// else {
		// 	for (auto x : cur)
		// 		col[x] = 2;
		// }
	}
	
	// for (int u = 0; u < n; ++u) {
	// 	if (col[u]) continue;
	// 	cycles.push_back({});
	// 	for (int v = u; col[v] == 0; v = a[v]) {
	// 		cycles.back().push_back(v);
	// 		col[v] = 3;
	// 	}
	// }

	
	vector<int> b(n, -1);
	// cerr << "yo\n";

	// for (auto b : {chains, cycles}) {
	// 	for (auto v : b) {
	// 		for (auto x : v) {
	// 			cerr << x + 1 << ' ';
	// 		}
	// 		cerr << '\n';
	// 	}
	// 	cerr << '\n';
	// }
	
	if (sz(chains) == 1 && sz(chains[0]) == 1) {
		int u = chains[0][0];
		col.assign(n, 0);
		int v = u;
		while (col[a[v]] == 0) {
			b[v] = a[v];
			col[v] = 1;
			v = a[v];
		}
		b[v] = u;
		// for (auto x : col)
			// assert(x == 1);
	} else {
		int m = sz(chains);
		rep(i, 0, m) {
			for (auto x : chains[i])
				b[x] = a[x];
			b[chains[i].back()] = chains[(i + 1) % m].front();
		}
	}
	rep(i, 0, n) if (b[i] < 0) b[i] = a[i];

	int k = 0;
	rep(i, 0, n) k += a[i] == b[i];
	
	cout << k << '\n';
	for (auto x : b) cout << x + 1 << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}