#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 19;
int a[N][2], cnt[N][2];
vector<int> loc[N];
vector<int> g[N];
bool vis[N], color[N];

vector<int> cmp;

bool dfs(int u, bool b) {
	if (vis[u]) {
		if (color[u] != b) return true;
		else return false;
	} else vis[u] = true, color[u] = b;
	cmp.eb(u);
	trav(v, g[u]) if (dfs(v, !b)) return true;
	return false;
}

void solve() {
	int n; cin >> n;

	rep(i, 0, n) cnt[i][0] = cnt[i][1] = 0, loc[i].clear();

	rep(b, 0, 2) rep(i, 0, n) cin >> a[i][b], --a[i][b];
	
	rep(i, 0, n) loc[a[i][0]].eb(i << 1|0), loc[a[i][1]].eb(i << 1|1);

	rep(x, 0, n) if (sz(loc[x]) != 2) return void(cout << "-1\n");

	rep(u, 0, 2 * n) vis[u] = false, color[u] = 0, g[u].clear();
	rep(x, 0, n) {
		g[loc[x][0]].eb(loc[x][1]);
		g[loc[x][1]].eb(loc[x][0]);
		g[x << 1|0].eb(x << 1|1);
		g[x << 1|1].eb(x << 1|0);
	}

	vector<int> ans;
	rep(u, 0, 2 * n) {
		if (vis[u]) continue;
		cmp.clear();
		if (dfs(u, u & 1)) return void(cout << "-1\n");
		vector<int> z[2];
		trav(v, cmp) z[color[v] != (v & 1)].eb(v / 2 + 1);
		int mn = 0; if (sz(z[0]) > sz(z[1])) mn = 1;
		trav(x, z[mn]) ans.eb(x);
	}

	sort(all(ans)); ans.resize(unique(all(ans)) - begin(ans));
	cout << sz(ans) << '\n'; trav(v, ans) cout << v << ' '; cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}