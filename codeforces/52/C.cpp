#include <iostream>
#include <sstream>
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;
const int N = 1 << 18;
const int inf = 1e9;
int n, a[N], u[N << 1]; ll t[N << 1];

void build(int v = 1, int l = 0, int r = n - 1) {
	u[v] = inf;
	if (l == r) t[v] = a[l];
	else {
		int m = (l + r) >> 1;
		build(v << 1, l, m);
		build(v << 1|1, m + 1, r);
		t[v] = min(t[v << 1], t[v << 1|1]);
	}
}

void apply(int val, int v) {
	t[v] += val;
	if (u[v] != inf) u[v] += val;
	else u[v] = val;
}

void push(int v) {
	if (u[v] != inf) {
		apply(u[v], v << 1);
		apply(u[v], v << 1|1);
		u[v] = inf;
	}
}

void update(int val, int lo, int hi, int v = 1, int l = 0, int r = n - 1) {
	if (l == lo && r == hi) {
		apply(val, v);
		return;
	}
	push(v);
	int m = (l + r) / 2;
	if (hi <= m) update(val, lo, hi, v << 1, l, m);
	else if (lo > m) update(val, lo, hi, v << 1|1, m + 1, r);
	else {
		update(val, lo, m, v << 1, l, m);
		update(val, m + 1, hi, v << 1|1, m + 1, r);
	}
	t[v] = min(t[v << 1], t[v << 1|1]);
}

ll query(int lo, int hi, int v = 1, int l = 0, int r = n - 1) {
	if (lo == l && hi == r) return t[v];
	push(v);
	int m = (l + r) / 2;
	if (hi <= m) return query(lo, hi, v << 1, l, m);
	if (lo  > m) return query(lo, hi, v << 1|1, m + 1, r);
	return min(query(lo, m, v << 1, l, m), query(m + 1, hi, v << 1|1, m + 1, r));
}

void inc(int val, int l, int r) {
	if (l > r) {
		update(val, l, n - 1);
		update(val, 0, r);
	} else update(val, l, r);
}

ll rmq(int l, int r) {
	if (l > r) return min(query(l, n - 1), query(0, r));
	else return query(l, r);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n; rep(i, 0, n) cin >> a[i];
	build();
	int q; cin >> q; cin.get();
	while (q--) {
		string s; getline(cin, s);
		stringstream iss(s);
		int l, r, v; iss >> l >> r;
		if (iss >> v) inc(v, l, r);
		else cout << rmq(l, r) << '\n';
	}
}