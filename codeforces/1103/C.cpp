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

const int N = 2.5e5 + 20;
vector<int> g[N], bk[N];
bool vis[N], not_leaf[N];
int d[N], p[N];

int n, m, k, cur;
void dfs(int u) {
	vis[u] = 1;
	for (int v : g[u]) {
		if (v == p[u]) continue;
		if (vis[v]) bk[u].push_back(v);
		else {
			not_leaf[u] = 1;
			d[v] = d[u] + 1;
			p[v] = u;
			dfs(v);
		}
	}
}

void print(int u, int x) {
	for (; u != x; u = p[u]) cout << u << ' ';
	cout << u << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	rep(e, 0, m) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	p[1] = 0;
	d[1] = 1;
	dfs(1);

	int v = 0;
	for (int u = 1; u <= n; ++u)
		if (k * d[u] >= n) v = u;
	if (v) {
		cout << "PATH\n" << d[v] << '\n';
		print(v, 1);
		return 0;
	}

	cout << "CYCLES\n";
	for (int u = 1, c = 0; u <= n && c < k; ++u) {
		if (not_leaf[u]) continue;
		++c;
		assert(sz(bk[u]) > 1);
		int x = bk[u].front(), y = bk[u].back();
		if (d[x] > d[y]) swap(x, y);
		if ((d[y] - d[x] + 2) % 3) {
			cout << d[y] - d[x] + 2 << '\n';
			cout << u << ' ';
			print(y, x);
		} else if ((d[u] - d[x] + 1) % 3) {
			cout << d[u] - d[x] + 1 << '\n';
			print(u, x);
		} else if ((d[u] - d[y] + 1) % 3) {
			cout << d[u] - d[y] + 1 << '\n';
			print(u, y);
		} else assert(false);
	}
}