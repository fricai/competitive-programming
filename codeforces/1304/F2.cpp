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

const int M = 1 << 15, N = 52;

struct segtree {
	ll t[M << 1], lz[M << 1];
	int m;

	segtree() { }
	segtree(int x) : m{x} {
		fill_n(t, M << 1, 0);
		fill_n(lz, M << 1, 0);
	}

	void push(int v) {
		t[v] += lz[v];
		if (v < M) {
			lz[v << 1|0] += lz[v];
			lz[v << 1|1] += lz[v];
		}
		lz[v] = 0;
	} 

	int lo, hi;
	ll x;

	ll query(int v, int l, int r) {
		push(v);
		if (hi <= l || r <= lo) return 0;
		if (lo <= l && r <= hi) return t[v];
		int m = (l + r) / 2;
		ll res = max(query(v << 1, l, m), query(v << 1|1, m, r));
		t[v] = max(t[v << 1], t[v << 1|1]);
		return res;
	}
	ll query(int l, int r) { return lo = l, hi = r, query(1, 0, m); }

	void upd(int v, int l, int r) {
		push(v);
		if (hi <= l || r <= lo) return;
		if (lo <= l && r <= hi) return lz[v] += x, push(v);
		int m = (l + r) / 2;
		upd(v << 1, l, m); upd(v << 1|1, m, r);
		t[v] = max(t[v << 1], t[v << 1|1]);
	}
	void update(int l, int r, ll v) { lo = l; hi = r; x = v; upd(1, 0, m);  }
} t;
ll a[N][M + M], p[N][M];

int n, m, k;
ll s(int l, int r, int d, int u) { // [l, r) x [d, u), 0 <= l <= r <= m and 0 <= d <= u <= n
	ckmax(l, 0); ckmax(r, 0);
	ckmin(l, m); ckmin(r, m);
	ckmax(u, 0); ckmax(d, 0);
	ckmin(u, n); ckmin(d, n);
	return p[u][r] - p[u][l] - p[d][r] + p[d][l];
}
ll f(int i, int j) {  return s(j, j + k, i, i + 2); }

ll dp[N][M];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	rep(i, 0, n)
		rep(j, 0, m)
			cin >> a[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i - 1][j - 1];
	ll ans = 0;

	for (int j = 0; j < m; ++j) dp[0][j] = f(0, j), ckmax(ans, dp[0][j]);
	for (int i = 1; i < n; ++i) {
		t = segtree(m);
		rep(j, 0, m) t.update(j, j + 1, dp[i - 1][j]);
		
		for (int j = 0; j < k; ++j)
			t.update(0, j + 1, -a[i][j]);
		
		for (int j = 0; j < m; ++j) {
			dp[i][j] = t.query(0, m) + f(i, j);
			ckmax(ans, dp[i][j]);
			t.update(j - k + 1, j + 1, +a[i][j]);
			t.update(j + 1, j + k + 1, -a[i][j + k]);
		}
	}
	
	cout << ans << '\n';
}