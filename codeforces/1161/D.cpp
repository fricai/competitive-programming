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

// #pragma GCC optimize ("trapv")

const int N = 1 << 10, M = 998244353;
bool vis[N + N];
int col[N + N];
int n;
int ans;
vector<pair<int, bool>> g[N + N];
string s;

void add(int &x, int y) { x += y; if (M <= x) x -= M; }

bool odd(int u) {
	vis[u] = 1;
	for (auto [v, b] : g[u]) {
		bool nxt = col[u] ^ b;
		if (col[v] < 0) col[v] = nxt;
		else if (col[v] != nxt) return 1;
		if (!vis[v] && odd(v)) return 1;
	}
	return 0;
}

void f(int k) {
	rep(u, 0, n + n) g[u].clear();
	fill_n(vis, n + n, 0);
	fill_n(col, n + n, -1);
	for (int i = 0, j = n - 1; i < n; ++i, --j)
		g[i + n].emplace_back(j + n, 0);
	for (int i = 0, j = k - 1; i < k; ++i, --j)
		g[i].emplace_back(j, 0);
	
	rep(i, 0, n) {
		if (s[i] == '?') continue;
		bool c = s[i] == '1';
		g[i].emplace_back(i + n, c);
		g[i + n].emplace_back(i, c);
	}
	
	col[k - 1] = 1; rep(i, k, n) col[i] = 0;

	int x = 1;
	rep(u, k - 1, n) if (!vis[u] && odd(u)) return;
	rep(u, 0, n + n) {
		if (vis[u]) continue;
		col[u] = 0;
		if (odd(u)) return;
		add(x, x);
	}
	add(ans, x);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	reverse(all(s));
	n = sz(s);

	rep(i, 1, n) f(i);

	cout << ans << '\n';
}