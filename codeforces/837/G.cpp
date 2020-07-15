#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define f first
#define s second
#define eb(x...) emplace_back(x)

using ll = int64_t;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
template<class T>
pair<T, T> operator+(const pair<T, T> &a, const pair<T, T> &b) {
	return {a.f + b.f, a.s + b.s};
}

const int X = 2e5 + 5, N = 1 << 17, NC = 18 << 18;
int n, nc = 0;

int L[NC], R[NC], lo, hi;
pll val[NC];
pll sum(int v, int l = 0, int r = n) {
	if (r <= lo || hi <= l) return {0, 0};
	if (lo <= l && r <= hi) return val[v];
	int m = l + r >> 1;
	return sum(L[v], l, m) + sum(R[v], m, r);
}

int combine(int v, int l, int r) {
	L[v] = l; R[v] = r;
	val[v] = val[l] + val[r];
	return v;
}

pii *y;
template<class T> int insert(int v, T s, T e, int l, int r) {
	if (s == e) return v;
	if (r - l == 1) return val[++nc] = y[l], nc;
	int m = l + r >> 1; T b = lower_bound(s, e, m);
	return combine(++nc, insert(L[v], s, b, l, m), insert(R[v], b, e, m, r));
}
template<class T> void insert(int &v, T s, T e, pii a[]) {
	y = a; v = insert(v, s, e, 0, n);
}

pii a[N], b[N], c[N];
int build(int l = 0, int r = n) {
	if (r - l == 1) return val[++nc] = a[l], nc;
	int m = (l + r) / 2;
	return combine(++nc, build(l, m), build(m, r));
}

int t[2 * N], cmp[X]; vector<int> ord[2][X];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x1, x2; cin >> x1 >> x2;
		ord[0][++x1].eb(i);
		ord[1][++x2].eb(i);
		cmp[i << 1|0] = x1;
		cmp[i << 1|1] = x2;
		cin >> a[i].s >> b[i].f >> b[i].s >> c[i].s;
	}
	sort(cmp, cmp + 2 * n + 1);
	int s = unique(cmp, cmp + 2 * n + 1) - cmp;

	t[0] = build();
	for (int i = 1; i < s; ++i) {
		t[i] = t[i - 1];
		insert(t[i], all(ord[0][cmp[i]]), b);
		insert(t[i], all(ord[1][cmp[i]]), c);
	}

	int q; cin >> q; ll last = 0;
	while (q--) {
		int x; cin >> lo >> hi >> x; --lo;
		x = (x + last) % 1000000000;
		auto res = sum(t[upper_bound(cmp, cmp + s, x) - cmp - 1]);
		last = x * res.f + res.s;
		cout << last << '\n';
	}
}