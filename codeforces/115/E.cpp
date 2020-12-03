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

const int N = 1 << 18;
ll t[N << 1], lz[N << 1];
int c[N]; vector<pair<int, int>> I[N];

void push(int v) {
	t[v] += lz[v];
	if (v < N) {
		lz[v << 1|0] += lz[v];
		lz[v << 1|1] += lz[v];
	}
	lz[v] = 0;
}

int lo, hi; ll x;
void upd(int v, int l, int r) {
	push(v);
	if (hi <= l || r <= lo) return;
	if (lo <= l && r <= hi) return lz[v] = x, push(v);
	int m = (l + r) / 2;
	upd(v << 1, l, m); upd(v << 1|1, m, r);
	t[v] = max(t[v << 1], t[v << 1|1]);
}
void update(int l, int r, ll v) { lo = l, hi = r, x = v; upd(1, 0, N); }

ll query(int v, int l, int r) {
	push(v);
	if (hi <= l || r <= lo) return 0;
	if (lo <= l && r <= hi) return t[v];
	int m = (l + r) / 2;
	return max(query(v << 1, l, m), query(v << 1|1, m, r));
}
ll query(int l, int r) { return lo = l, hi = r, query(1, 0, N); }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	rep(i, 0, m) {
		int l, r, p;
		cin >> l >> r >> p;
		I[r].emplace_back(l, p);
	}

	for (int r = 1; r <= n; ++r) {
		update(r, r + 1, query(0, N));
		update(0, r, -c[r]);
		for (auto &[l, p] : I[r]) update(0, l, p);
	}
	cout << query(0, N);
}