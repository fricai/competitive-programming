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

const int N = 205, M = 1e9 + 7, inv2 = (M + 1) / 2;

int add(int x, int y) { return x += y, x < M ? x : x - M; }
int sub(int x, int y) { return x -= y, x < 0 ? x + M : x; }
int mul(ll x, int y) { return x * y % M; }
int bpow(int x, int y) {
	int res = 1;
	for (; y; y >>= 1, x = mul(x, x))
		if (y & 1) res = mul(res, x);
	return res;
}

int p[N][N];
vector<int> g[N];
int ans = 0;

vector<pair<int, int>> dfs(int u, int par, int dep) {
	vector<pair<int, int>> cur = {{u, dep}};

	for (int v : g[u]) {
		if (v == par) continue;
	
		auto nxt = dfs(v, u, dep + 1);

		for (auto [x, dx] : cur) {
			dx -= dep;
			for (auto [y, dy] : nxt) {
				dy -= dep;
				if (x < y) ans = add(ans, p[dx][dy]);
				else ans = add(ans, p[dy][dx]);
			}
		}
		cur.insert(end(cur), all(nxt));
	}
	return cur;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(e, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i)
		p[i][0] = 1;
	for (int j = 1; j <= n; ++j)
		p[0][j] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			p[i][j] = mul(add(p[i - 1][j], p[i][j - 1]), inv2);
	
	rep(u, 0, n) dfs(u, -1, 0);
	cout << mul(ans, bpow(n, M - 2)) << '\n';
}