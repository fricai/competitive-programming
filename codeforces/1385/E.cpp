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

const int N = 1 << 18;
vector<int> g[N];
bool t[N];
int color[N], a[N], b[N], out[N], timer = 0;

bool dfs(int u) {
	color[u] = 1;
	trav(v, g[u]) {
		if (color[v] == 2) continue;
		if (color[v] == 1) return true;
		if (dfs(v)) return true;
	}
	color[u] = 2;
	out[u] = ++timer;
	return false;
}

void solve() {
	int n, m; cin >> n >> m;

	rep(u, 0, n) color[u] = 0, g[u].clear();

	rep(e, 0, m) {
		int x;  cin >> x >> a[e] >> b[e]; t[e] = x;
		--a[e]; --b[e];
		if (t[e]) g[a[e]].eb(b[e]);
	}

	rep(u, 0, n) 
		if (color[u] == 0 && dfs(u))
			return void(cout << "NO\n");

	cout << "YES\n";
	rep(e, 0, m) {
		if (!t[e]) if (out[a[e]] < out[b[e]]) swap(a[e], b[e]);
		cout << ++a[e] << ' ' << ++b[e] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}