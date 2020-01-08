#include <iostream>
#include <vector>
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const int N = 1 << 18;
vector<int> g[N]; int n;
int in[N], out[N], a[N], t[N << 1], u[N << 1];
bool d[N];

void apply(int v, int val, int s) {
	t[v] += s * val;
	u[v] += val;
}

void push(int v, int l, int r) {
	if (u[v]) {
		int m = (l + r) >> 1;
		apply(v << 1, u[v], m - l + 1);
		apply(v << 1|1, u[v], r - m);
		u[v] = 0;
	}
}

void inc(int val, int lo, int hi, int v = 1, int l = 0, int r = n - 1) {
	if (lo == l && hi == r) apply(v, val, r - l + 1);
	else {
		int m = (l + r) >> 1;
		push(v, l, r);
		if (hi <= m) inc(val, lo, hi, v << 1, l, m);
		else if (lo > m) inc(val, lo, hi, v << 1|1, m + 1, r);
		else {
			inc(val, lo, m, v << 1, l, m);
			inc(val, m + 1, hi, v << 1|1, m + 1, r);
		}
		t[v] = t[v << 1] + t[v << 1|1];
	}
}

int query(int p, int v = 1, int l = 0, int r = n - 1) {
	if (l == r) return t[v];
	push(v, l, r);
	int m = (l + r) >> 1;
	if (p <= m) return query(p, v << 1, l, m);
	else return query(p, v << 1|1, m + 1, r);
}

int timer = 0;
void dfs(int u = 0, int p = -1) {
	in[u] = timer++;
	for (int v : g[u]) {
		if (v != p) {
			d[v] = !d[u];
			dfs(v, u);
		}
	}
	out[u] = timer;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> n >> q;
	rep(i, 0, n) cin >> a[i];
	rep(i, 1, n) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs();
	while (q--) {
		int c, u; cin >> c >> u; --c; --u;
		if (c)
			cout << a[u] - (2 * d[u] - 1) * query(in[u]) << '\n';
		else {
			int v; cin >> v;
			if (d[u]) v = -v;
			inc(v, in[u], out[u] - 1);
		}
	}
}