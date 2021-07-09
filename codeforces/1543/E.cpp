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

const int lgK = 4;
int c[lgK + 1][1 << (1 << lgK)];

void solve() {
	int k; cin >> k;
	
	int n = 1 << k, m = k << (k - 1);
	
	vector<vector<int>> g(n);
	for (auto &v : g) v.reserve(k);

	// rep(u, 0, n) rep(i, 0, k) g[u].push_back(u ^ (1 << i));

	rep(e, 0, m) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<int> pi(n, -1);
	queue<int> q;

	pi[0] = 0;
	rep(i, 0, k) {
		int u = g[0][i];
		q.push(u);
		pi[u] = 1 << i;
	}
	
	while (!q.empty()) {
		int u = q.front(); q.pop();
		int pre = -1;
		for (int v : g[u]) {
			if (0 <= pi[v]) {
				if (pre < 0) pre = pi[v];
				else pi[u] = pre | (pre ^ pi[v]);
			} else if (pi[v] == -1)
				q.push(v), pi[v] = -2;
		}
	}
	
	vector<int> p(n);
	rep(i, 0, n) p[pi[i]] = i;
	for (auto x : p) cout << x << ' ';
	cout << '\n';

	if (k & (k - 1))
		cout << "-1\n";
	else {
		int j = 31 - __builtin_clz(k);
		rep(u, 0, n) cout << c[j][pi[u]] << ' ';
		cout << '\n';
		
		// vector<int> c(n);
		// rep(u, 0, n)
		// 	rep(i, 0, k)
		// 		if (u >> i & 1)
		// 			c[p[u]] ^= i;
		// for (auto x : c)
		// 	cout << x << ' ';
		// cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	c[0][0] = 0; c[0][1] = 0;
	for (int b = 1, r = 0; r < lgK; b <<= 1, ++r)
		rep(u, 0, 1 << b)
			rep(v, 0, 1 << b) {
				c[r + 1][v << b | u] = c[r][v] ^ c[r][u];
				if (__builtin_popcount(v) & 1) c[r + 1][v << b | u] |= b;
			}
			
	int t; cin >> t;
	while (t--) solve();
}