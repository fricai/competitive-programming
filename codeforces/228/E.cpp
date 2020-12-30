#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 7, M = 1 << 14;
int a[M], b[M], c[M];
bool val[N], vis[N];
vector<int> g[N];

int n, m;
bool dfs(int u, bool x) {
	val[u] = x; vis[u] = true;
	for (int e : g[u]) {
		int v = a[e] ^ b[e] ^ u;
		bool new_x = c[e] ^ 1 ^ x;
		if (!vis[v]) {
			if (!dfs(v, new_x)) return false;
		} else if (new_x != val[v]) return false;
	}
	return true;
}

bool solve(bool init) {
	fill(vis, vis + n, false);
	rep(u, 0, n) if (!vis[u] && !dfs(u, init)) return false;
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	rep(e, 0, m) {
		cin >> a[e] >> b[e] >> c[e], --a[e], --b[e];
		g[a[e]].push_back(e);
		g[b[e]].push_back(e);
	}

	if (solve(0)) {
		int cnt = 0;
		rep(u, 0, n) cnt += val[u];
		cout << cnt << '\n';
		rep(u, 0, n) if (val[u]) cout << u + 1 << ' ';
	} else cout << "Impossible";
}