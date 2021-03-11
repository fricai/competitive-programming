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

const int N = 1 << 17;
vector<int> g[N];

short col[N];
bool cycle(int u) {
	col[u] = -1;
	for (int v : g[u]) {
		if (col[v]) {
			if (col[v] < 0) return 1;
		} else {
			if (cycle(v)) return 1;
		}
	}
	col[u] = +1;
	return 0;
}


bool vis[N][2];
int p[N][2];

void dfs(int u, bool b) {
	vis[u][b] = 1;
	for (int v : g[u]) if (!vis[v][!b]) p[v][!b] = u, dfs(v, !b);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(u, 0, n) {
		int c; cin >> c;
		g[u].resize(c);
		for (auto &x : g[u]) cin >> x, --x;
	}
	int s; cin >> s; --s;

	p[s][0] = -1;
	dfs(s, 0);

	rep(u, 0, n) {
		if (!g[u].empty() || !vis[u][1]) continue;

		vector<int> ans;
		for (int v = u, b = 1; v != -1; v = p[v][b], b ^= 1)
			ans.push_back(v);
		reverse(all(ans));

		cout << "Win\n";
		for (auto v : ans) cout << v + 1 << ' ';
		cout << '\n';
		return 0;
	}

	cout << (cycle(s) ? "Draw" : "Lose") << '\n';
}