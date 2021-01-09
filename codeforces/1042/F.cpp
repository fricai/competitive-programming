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

const int N = 1 << 20;
vector<int> g[N];
multiset<int> s[N];
int d[N];
int n, k;

void dfs(int u) {
	for (int v : g[u]) {
		g[v].erase(find(all(g[v]), u));
		d[v] = d[u] + 1;
		dfs(v);
		if (sz(s[v]) > sz(s[u])) swap(s[u], s[v]);
		for (auto a : s[v]) {
			auto it = s[u].upper_bound(k + 2 * d[u] - a);
			if (it != begin(s[u])) {
				--it;
				ckmax(a, *it);
				s[u].erase(it);
			}
			s[u].insert(a);
		}
	}
	if (g[u].empty()) s[u] = {d[u]};
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	rep(e, 1, n) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int root = 0;
	for (int u = 1; u <= n; ++u) if (sz(g[u]) > 1) root = u;
	assert(root);
	dfs(root);
	cout << sz(s[root]);
}