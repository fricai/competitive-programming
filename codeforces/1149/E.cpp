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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<int> h(n);
	for (auto &x : h) cin >> x;
	vector<vector<int>> g(n);
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
	}

	vector<int> mex(n);
	vector<bool> vis(n);
	auto dfs = [&](auto &&self, int u) {
		if (vis[u])
			return mex[u];
		
		vis[u] = 1;
		vector<bool> taken(sz(g[u]) + 1);
		for (auto v : g[u]) {
			int nxt = self(self, v);
			if (nxt < sz(g[u]))
				taken[nxt] = 1;
		}
		
		mex[u] = 0;
		while (taken[mex[u]]) ++mex[u];
		return mex[u];
	};
	rep(u, 0, n) if (!vis[u]) dfs(dfs, u);
	
	vector<int> opt(n);
	rep(u, 0, n) opt[mex[u]] ^= h[u];

	int win = -1;
	rep(i, 0, n) if (opt[i]) win = i;
	
	if (win < 0)
		return cout << "LOSE\n", 0;

	vector<int> cities;
	rep(u, 0, n) if (mex[u] == win) cities.push_back(u);
		
	auto clear = [&](int v) {
		h[v] ^= opt[mex[v]];
		opt[mex[v]] = 0;
	};

	bool changed = 0;
	for (auto x : cities) {
		if ((opt[win] ^ h[x]) < h[x]) {
			clear(x);
			
			for (auto v : g[x])
				clear(v);
			
			changed = 1;
			break;
		}
	}
	
	assert(changed);

	cout << "WIN\n";
	rep(u, 0, n) cout << h[u] << ' ';
	cout << '\n';
}