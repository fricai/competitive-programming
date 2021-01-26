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

const int N = 1 << 16, K = 50 + 2, inf = 1e8;
int f[K][N], a[N], p[N];

struct S {
	int t[N << 1], lz[N << 1];
	int lo, hi, x;

	S() { fill_n(t, 2 * N, -inf); fill_n(lz, 2 * N, 0); }

	void push(int v) {
		t[v] += lz[v];
		if (v < N) {
			lz[v << 1|0] += lz[v];
			lz[v << 1|1] += lz[v];
		}
		lz[v] = 0;
	}

	void upd(int v, int l, int r) {
		push(v);
		if (hi <= l || r <= lo) return;
		if (lo <= l && r <= hi) return lz[v] = x, push(v);
		int m = (l + r) / 2;
		upd(v << 1, l, m); upd(v << 1|1, m, r);
		t[v] = max(t[v << 1], t[v << 1|1]);
	}

	void update(int l, int r, int v) { lo = l; hi = r; x = v; upd(1, 0, N); }

	int query(int v, int l, int r) {
		push(v);
		if (hi <= l || r <= lo) return -inf;
		if (lo <= l && r <= hi) return t[v];
		int m = (l + r) / 2;
		return max(query(v << 1, l, m), query(v << 1|1, m, r));
	}

	int query(int l, int r) {
		lo = l; hi = r;
		return query(1, 0, N);
	}
} t[2];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	t[0].update(0, 1, +inf);

	for (int c = 1, pre = 0, cur = 1; c <= k; ++c, pre ^= 1, cur ^= 1) {
		t[cur] = S();
		for (int i = 1; i <= n; ++i) {
			t[pre].update(p[a[i]], i, +1);
			t[cur].update(i, i + 1, inf + t[pre].query(0, i));
			p[a[i]] = i;
		}
		for (int i = 1; i <= n; ++i) p[a[i]] = 0;
	}
	
	cout << t[k & 1].query(n, n + 1);
}