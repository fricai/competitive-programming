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

const int N = 1 << 16;

void solve() {
	int k; cin >> k;
	
	int n = 1 << k, m = k * n / 2;
	
	vector<vector<int>> g(n);
	rep(e, 0, m) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<int> pi(n, -1), cur;
	
	pi[0] = 0;
	rep(i, 0, k) {
		int u = g[0][i];
		cur.push_back(u);
		pi[u] = 1 << i;
	}
	
	rep(b, 1, k) {
		vector<int> nxt;
		
		for (auto u : cur) {
			for (auto v : g[u]) {
				if (pi[v] != -1) continue;	
				for (auto w : g[v]) {
					if (w == u || pi[w] == -1) continue;
					pi[v] = pi[u] | (pi[u] ^ pi[w]);
					nxt.push_back(v);
					break;
				}
			}
		}
		
		cur = move(nxt);
	}

	vector<int> p(n);
	rep(i, 0, n) p[pi[i]] = i;
	for (auto x : p) cout << x << ' ';
	cout << '\n';
	if (k & (k - 1)) cout << "-1\n";
	else {
		vector<int> c(n);
		rep(u, 0, n)
			rep(i, 0, k)
				if (u >> i & 1)
					c[p[u]] ^= i;
		for (auto x : c)
			cout << x << ' ';
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}