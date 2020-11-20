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
ll s[N << 1];
int mn[N << 1], lz[N << 1], n;

void push(int v, ll sz) {
	if (lz[v]) {
		s[v] = sz * lz[v];
		mn[v] = lz[v];
		if (sz > 1) lz[v << 1] = lz[v << 1|1] = lz[v];
		lz[v] = 0;
	}
}

int x, val;
int query(int v, int l, int r) {
	push(v, r - l);
	if (r <= x) return 0;
	if (x <= l && s[v] <= val) return val -= s[v], r - l;
	if (mn[v] > val || r - l == 1) return 0;
	int m = (l + r) / 2;
	return query(v << 1, l, m) + query(v << 1|1, m, r);
}
int query(int a, int b) { return x = a, val = b, query(1, 0, n); }

int get(int v, int l, int r) {
	push(v, r - l);
	if (val <= mn[v]) return r;
	if (r - l == 1) return l;
	int m = (l + r) / 2;
	int res = get(v << 1, l, m);
	return res < m ? res : get(v << 1|1, m, r);
}
int get(int v) { return val = v, get(1, 0, n); }

int lo, hi;
void upd(int v, int l, int r) {
	push(v, r - l);
	if (hi <= l || r <= lo) return;
	if (lo <= l && r <= hi) return lz[v] = val, push(v, r - l);
	int m = (l + r) / 2;
	upd(v << 1, l, m); upd(v << 1|1, m, r);
	s[v] = s[v << 1] + s[v << 1|1];
	mn[v] = mn[v << 1|1];
}
void update(int l, int r, int v) { lo = l; hi = r; val = v; upd(1, 0, n); }

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int q; cin >> n >> q;

	rep(i, 0, n) {
		int a; cin >> a;
		update(i, i + 1, a);
	}

	while (q--) {
		short t; cin >> t;
		if (--t) {
			int x, v; cin >> x >> v;
			cout << query(--x, v) << '\n';
		} else {
			int x, v; cin >> x >> v;
			update(get(v), x, v);
		}
	}
}