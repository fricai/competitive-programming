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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 18, M = 1 << 19, Q = 1 << 21, B = 20;
struct event { bool delt; int v; } E[Q];

int delt[M]; pair<int, int> edges[M];

int n, m;

int val[N];

int nxt[N + M], p[N + M][B];
int head(int u) { return nxt[u] != u ? nxt[u] = head(nxt[u]) : u; }
void join(int e) {
	auto [u, v] = edges[e];
	u = head(u); v = head(v);
	if (u == v) return;
	p[u][0] = p[v][0] = nxt[u] = nxt[v] = e + n;
}

vector<int> g[N + M];
int in[N + M], out[N + M], inv[N], timer = 0;
void dfs(int u) {
	in[u] = timer;
	if (u < n) inv[timer++] = u;
	for (int v : g[u]) dfs(v);
	out[u] = timer;
}

pair<int, int> t[N << 1];
void build(int v, int l, int r) {
	if (r - l == 1) {
		t[v] = {val[inv[l]], inv[l]};
		return;
	}
	int m = (l + r) >> 1;
	build(v << 1|0, l, m);
	build(v << 1|1, m, r);
	t[v] = max(t[v << 1], t[v << 1|1]);
}
int lo, hi, x;
pair<int, int> find(int v, int l, int r) {
	if (hi <= l || r <= lo) return {-1, -1};
	if (lo <= l && r <= hi) return t[v];
	int m = (l + r) >> 1;
	return max(find(v << 1, l, m), find(v << 1|1, m, r));
}
void clear(int v, int l, int r) {
	if (r - l == 1) return void(t[v] = {0, inv[l]});
	int m = (l + r) >> 1;
	if (x < m) clear(v << 1, l, m);
	else clear(v << 1|1, m, r);
	t[v] = max(t[v << 1], t[v << 1|1]);
}
int query(int l, int r) {
	lo = l, hi = r; auto p = find(1, 0, n);
	x = in[p.second]; clear(1, 0, n);
	return p.first;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> n >> m >> q;
	iota(nxt, nxt + n + m, 0);
	fill(delt, delt + m, -1);

	rep(u, 0, n) cin >> val[u];
	rep(e, 0, m) {
		int a, b; cin >> a >> b;
		edges[e] = {--a, --b};
	}
	rep(z, 0, q) {
		int t, v; cin >> t >> v;
		E[z] = {bool(--t), --v};
		if (t) delt[v] = z;
	}
	rep(e, 0, m) if (delt[e] < 0) delt[e] = q, E[q++] = {1, e};
	
	per(z, 0, q) if (E[z].delt) join(E[z].v);
	
	rep(u, 0, n + m) {
		if (nxt[u] == u) p[u][0] = u;
		if (p[u][0] != u) g[p[u][0]].push_back(u);
	}
	rep(j, 1, B) rep(u, 0, n + m) p[u][j] = p[p[u][j - 1]][j - 1];

	rep(u, 0, n) {
		int rt = p[u][B - 1];
		if (!out[rt]) dfs(rt);		
	}
	
	build(1, 0, n);

	rep(z, 0, q) {
		if (E[z].delt) continue;
		int u = E[z].v;
		per(b, 0, B) if (n <= p[u][b] && z < delt[p[u][b] - n]) u = p[u][b];
		cout << query(in[u], out[u]) << '\n';
	}
}