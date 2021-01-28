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

struct TwoSat {
	int N;
	vector<vector<int>> gr;
	vector<int> values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2 * n) {}

	void either(int f, int j) {
		f = max(2 * f, -1 - 2 * f);
		j = max(2 * j, -1 - 2 * j);
		gr[f].push_back(j ^ 1);
		gr[j].push_back(f ^ 1);
	}

	vector<int> val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x >> 1] == -1)
				values[x >> 1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};


const int N = 1 << 14, inf = 1e9 + 10;
int x[N], y[N];
int n;

TwoSat solver;
int ord_x[N], ord_y[N];

int t_x[N << 1], t_y[N << 1];
int c;

void build_x(int v, int l, int r) {
	if (r - l == 1) return void(t_x[v] = ~ord_x[l]);
	t_x[v] = ++c;
	int m = (l + r) / 2;
	build_x(v << 1, l, m); build_x(v << 1|1, m, r);
	solver.either(~t_x[v], t_x[v << 1|0]);
	solver.either(~t_x[v], t_x[v << 1|1]);
}

void build_y(int v, int l, int r) {
	if (r - l == 1) return void(t_y[v] = ord_y[l]);
	t_y[v] = ++c;
	int m = (l + r) / 2;
	build_y(v << 1, l, m); build_y(v << 1|1, m, r);
	solver.either(~t_y[v], t_y[v << 1|0]);
	solver.either(~t_y[v], t_y[v << 1|1]);
}

int lo, hi, p;

void upd_x(int v, int l, int r) {
	if (hi <= l || r <= lo) return;
	if (lo <= l && r <= hi) return solver.either(p, t_x[v]);
	int m = (l + r) / 2;
	upd_x(v << 1, l, m); upd_x(v << 1|1, m, r);
}
void add_x(int l, int r, int i) { p = i, lo = l, hi = r, upd_x(1, 0, N); }

void upd_y(int v, int l, int r) {
	if (hi <= l || r <= lo) return;
	if (lo <= l && r <= hi) return solver.either(p, t_y[v]);
	int m = (l + r) / 2;
	upd_y(v << 1, l, m); upd_y(v << 1|1, m, r);
}
void add_y(int l, int r, int i) { p = i, lo = l, hi = r, upd_y(1, 0, N); }

int inv_x[N], inv_y[N];

bool solve(int d) {
	c = n;

	solver = 3 * N;
	build_x(1, 0, N);
	build_y(1, 0, N);

	int l, r;

	l = r = 0;
	rep(i, 0, n) {
		int s = ord_x[i];
		while (l < n && d <= x[s] - x[ord_x[l]]) ++l;
		add_x(l, i, ~s);
	}

	l = r = 0;
	rep(i, 0, n) {
		int s = ord_x[i];
		while (r < n && y[ord_y[r]] - x[s] < d) ++r;
		while (l < n && d <= x[s] - y[ord_y[l]]) ++l;
		add_y(l, r, ~s);
	}

	l = r = 0;
	rep(i, 0, n) {
		int s = ord_y[i];
		while (r < n && x[ord_x[r]] - y[s] < d) ++r;
		while (l < n && d <= y[s] - x[ord_x[l]]) ++l;
		add_x(l, r, s);
	}

	l = r = 0;
	rep(i, 0, n) {
		int s = ord_y[i];
		while (l < n && d <= y[s] - y[ord_y[l]]) ++l;
		add_y(l, i, s);
	}

	return solver.solve();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	rep(i, 0, n) cin >> x[i] >> y[i], ord_x[i] = ord_y[i] = i;
	sort(ord_x, ord_x + n, [&](int i, int j) { return x[i] < x[j]; });
	sort(ord_y, ord_y + n, [&](int i, int j) { return y[i] < y[j]; });

	rep(i, 0, n) inv_x[ord_x[i]] = inv_y[ord_y[i]] = i;


	int l = 0, r = inf;
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		(solve(m) ? l : r) = m;
	}

	cout << l << '\n';
}