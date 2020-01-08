#include <algorithm>
#include <iostream>
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const int N = 1 << 20;
struct node {
	int one, zero, inc, dec;
	node() { }
	node(bool b) : one{b}, zero{!b}, inc{1}, dec{1} { }
	node(node l, node r) {
		zero = l.zero + r.zero;
		one = l.one + r.one;
		inc = max({l.zero + r.one, l.zero + r.inc, l.inc + r.one});
		dec = max({l.one + r.zero, l.one + r.dec, l.dec + r.zero});
	}
	void flip() {
		swap(one, zero);
		swap(inc, dec);
	}
};

int n;
node t[N << 1];
bool u[N << 1];

void apply(int v) {
	u[v] ^= true; t[v].flip();
}

void set(int v) {
	t[v] = node(t[v << 1], t[v << 1|1]);
}

void push(int v) {
	if (u[v]) {
		apply(v << 1);
		apply(v << 1|1);
		u[v] = false;
	}
}

void flip(int lo, int hi, int v = 1, int l = 0, int r = n - 1) {
	if (lo == l && r == hi) apply(v);
	else {
		int m = (l + r) >> 1;
		push(v);
		if (hi <= m) flip(lo, hi, v << 1, l, m);
		else if (lo > m) flip(lo, hi, v << 1|1, m + 1, r);
		else {
			flip(lo, m, v << 1, l, m);
			flip(m + 1, hi, v << 1|1, m + 1, r);
		}
		set(v);
	}
}

void build(int v = 1, int l = 0, int r = n - 1) {
	if (l == r) {
		char c; cin >> c;
		t[v] = node(c != '4');
	}
	else {
		int m = (l + r) >> 1;
		build(v << 1, l, m);
		build(v << 1|1, m + 1, r);
		set(v);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> n >> q;
	build();
	while (q--) {
		string s; cin >> s;
		if (s == "count") cout << t[1].inc << '\n';
		else {
			int l, r; cin >> l >> r; --l; --r;
			flip(l, r);
		}
	}
}