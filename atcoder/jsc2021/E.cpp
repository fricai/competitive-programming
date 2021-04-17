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

const int N = 1 << 19;

int lg(int n) {
	return n ? 1 + lg(n / 2) : 0;
}

vector<int> g[N];
vector<pair<int, int>> atleast_one;

void rec(int k, int l, int r) {
	if (k < 0 || r < l) return;
	
	if (k) {
		int i = l, j = r;
		for (; i < j; ++i, --j) {
			g[i].emplace_back(j);
			g[j].emplace_back(i);
		}
		rec(k - 1, l, i - 1);
		rec(k - 1, j + 1, r);
		return;
	}
	
	for (int i = l, j = r; i <= j; ++i, --j)
		atleast_one.emplace_back(i, j);
}

string s;

const int A = 26;
bool vis[N];
int cc[N];
int f[N][A];
int mx[N];
int smx[N];

int cnt = 0;
void dfs(int u) {
	vis[u] = 1;
	cc[u] = cnt;
	++f[cnt][s[u] - 'a'];
	for (int v : g[u]) if (!vis[v]) dfs(v);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k >> s;
	int n = sz(s);
	
	if (k > lg(n)) return cout << "impossible\n", 0;

	rec(k, 0, n - 1);

	int sum = 0;
	rep(u, 0, n) {
		if (vis[u]) continue;
		dfs(u);
		mx[cnt] = max_element(f[cnt], f[cnt] + A) - f[cnt];
		sum += f[cnt][mx[cnt]];
		smx[cnt] = mx[cnt] ? 0 : 1;
		rep(c, 0, A) if (mx[cnt] != c && f[cnt][smx[cnt]] < f[cnt][c]) smx[cnt] = c;
		++cnt;
	}

	int res = atleast_one.empty() ? sum : -1;
	for (auto [x, y] : atleast_one) {
		x = cc[x]; y = cc[y];
		if (x == y) continue;
		if (mx[x] != mx[y]) ckmax(res, sum);
		else {
			ckmax(res, sum - f[x][mx[x]] + f[x][smx[x]]);
			ckmax(res, sum - f[y][mx[y]] + f[y][smx[y]]);
		}
	}
	if (res < 0) cout << "impossible\n";
	else cout << n - res << '\n';
}