#include <iostream>
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const int S = 26;
struct node {
	int f[S];
	node() { }
	node(int c, int x = 1) { 
		rep(i, 0, S) f[i] = 0;
		f[c] = x;
	}
	node operator+(node a) {
		node res;
		rep(i, 0, S) res.f[i] = f[i] + a.f[i];
		return res;
	}
};

int n;
const int N = 1 << 17;
node t[N << 1];
int u[N << 1];

void build(int v = 1, int l = 0, int r = n - 1) {
	if (l == r) {
		char c; cin >> c;
		t[v] = node(c - 'a');
	} else {
		int m = (l + r) >> 1;
		build(v << 1, l, m);
		build(v << 1|1, m + 1, r);
		t[v] = t[v << 1] + t[v << 1|1];
	}
}

void apply(int v, int sz, int x) {
	t[v] = node(x, sz);
	u[v] = x;
}

void push(int v, int l, int r) {
	if (u[v] != -1) {
		int m = (l + r) >> 1;
		apply(v << 1, m - l + 1, u[v]);
		apply(v << 1 | 1, r - m, u[v]);
		u[v] = -1;
	}
}

node freq(int lo, int hi, int v = 1, int l = 0, int r = n - 1)  {
	if (l == lo && r == hi) return t[v];
	push(v, l, r);
	int m = (l + r) >> 1;
	if (hi <= m) return freq(lo, hi, v << 1, l, m);
	if (lo  > m) return freq(lo, hi, v << 1|1, m + 1, r);
	return freq(lo, m, v << 1, l, m) + freq(m + 1, hi, v << 1|1, m + 1, r);
}

void upd(int lo, int hi, int val, int v = 1, int l = 0, int r = n - 1) {
	if (lo == l && hi == r) apply(v, r - l + 1, val);
	else {
		push(v, l, r);
		int m = (l + r) >> 1;
		if (hi <= m) upd(lo, hi, val, v << 1, l, m);
		else if (lo > m) upd(lo, hi, val, v << 1|1, m + 1, r);
		else {
			upd(lo, m, val, v << 1, l, m);
			upd(m + 1, hi, val, v << 1|1, m + 1, r);
		}
		t[v] = t[v << 1] + t[v << 1|1];
	}
}

char get(int p, int v = 1, int l = 0, int r = n - 1) {
	if (l == r) {
		rep(c, 0, S) if (t[v].f[c]) return c + 'a';
	}
	push(v, l, r);
	int m = (l + r) >> 1;
	if (p <= m) return get(p, v << 1, l, m);
	else return get(p, v << 1|1, m + 1, r);
}

void opt(int l, int r, bool k) {
	node x = freq(l, r);
	if (k) {
		int prev = l;
		rep(c, 0, S) {
			if (x.f[c]) {
				upd(prev, prev + x.f[c] - 1, c);
				prev += x.f[c];
			}
		}
	} else {
		int nxt = r;
		rep(c, 0, S) {
			if (x.f[c]) {
				upd(nxt - x.f[c] + 1, nxt, c);
				nxt -= x.f[c];
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(i, 0, N << 1) u[i] = -1;
	int q; cin >> n >> q;
	build();
	while (q--) {
		int i, j, k; cin >> i >> j >> k; --i, --j;
		opt(i, j, k);
	}
	rep(i, 0, n) cout << get(i);
}