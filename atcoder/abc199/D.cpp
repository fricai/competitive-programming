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

const int N = 21;
vector<int> g[N];
bool vis[N];

vector<int> cc;
void dfs(int u) {
	cc.push_back(u);
	vis[u] = 1;
	for (int v : g[u]) if (!vis[v]) dfs(v);
}

int nxt(int x, int b) {
	x += b + 1;
	if (x > 3) x -= 3;
	return x;
}

short col[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(e, 0, m) {
		int u, v; cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	ll res = 1;
	rep(u, 0, n) {
		if (vis[u]) continue;
		cc.clear(); dfs(u);
		int mx = sz(cc) - 1;
		mx = 1 << mx;

		ll tmp = 0;
		
		rep(S, 0, mx) {
			for (auto u : cc) col[u] = 0;
			
			col[u] = 1;
			bool valid = 1;
			int T = S;
			int cur = 0;
			for (auto u : cc)
				for (auto v : g[u])
					if (col[v]) valid &= col[u] != col[v];
					else col[v] = nxt(col[u], T >> cur++ & 1);
			tmp += valid;
		}

		res *= 3 * tmp;
	}
	cout << res << '\n';
}