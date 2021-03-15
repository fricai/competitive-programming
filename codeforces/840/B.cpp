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

const int N = 3e5 + 10;
vector<int> g[N];
bool vis[N];
int d[N], a[N], b[N];
vector<int> res;

bool dfs(int u, int p) {
	vis[u] = 1;
	bool parity = d[u];
	for (int e : g[u]) {
		if (p == e) continue;
		int v = a[e] ^ b[e] ^ u;
		if (vis[v]) continue;
		if (dfs(v, e)) {
			res.push_back(e + 1);
			parity ^= 1;
		} 
	}
	return parity;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	bool parity = 0;
	int sink = -1;
	rep(u, 0, n) {
		cin >> d[u];
		if (d[u] < 0) sink = u;
		else parity ^= d[u];
	}
	if (parity) {
		if (sink < 0) return cout << "-1\n", 0;
		d[sink] = 1;
	}
	rep(u, 0, n) if (d[u] < 0) d[u] = 0;
	rep(e, 0, m) {
		cin >> a[e] >> b[e]; --a[e]; --b[e];
		g[a[e]].push_back(e);
		g[b[e]].push_back(e);
	}
	assert(!dfs(0, -1));
	
	cout << sz(res) << '\n';
	for (auto x : res) cout << x << ' ';
}