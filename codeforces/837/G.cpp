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

const int X = 2e5 + 5, N = 75005, NC = 6e6;
int n, nc = 0;

int L[NC], R[NC], lo, hi;
pll val[NC];
pll sum(int v, int l = 0, int r = n) {
	if (r <= lo || hi <= l) return {0, 0};
	if (lo <= l && r <= hi) return val[v];
	int m = (l + r) / 2;
	return sum(L[v], l, m) + sum(R[v], m, r);
}

int combine(int v, int l, int r) {
	L[v] = l; R[v] = r;
	val[v] = val[l] + val[r];
	return v;
}

pii z; int p;
int insert(int v, int l = 0, int r = n) {
	if (r - l == 1) return val[++nc] = z, nc;
	int m = (l + r) / 2;
	if (p < m) return combine(++nc, insert(L[v], l, m), R[v]);
	return combine(++nc, L[v], insert(R[v], m, r));
}

pii a[N], b[N], c[N];
int build(int l = 0, int r = n) {
	if (r - l == 1) return val[++nc] = a[l], nc;
	int m = (l + r) / 2;
	return combine(++nc, build(l, m), build(m, r));
}

int t[X]; vector<int> ord[2][X];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x1, x2; cin >> x1 >> x2;
		ord[0][++x1].eb(i);
		ord[1][++x2].eb(i);
		cin >> a[i].s >> b[i].f >> b[i].s >> c[i].s;
	}

	t[0] = build();
	for (int x = 1; x < X; ++x) {
		t[x] = t[x - 1];
		for (int j : ord[0][x])
			z = b[j], p = j, t[x] = insert(t[x]);
		for (int j : ord[1][x])
			z = c[j], p = j, t[x] = insert(t[x]);
	}

	int q; cin >> q; ll last = 0;
	while (q--) {
		int x; cin >> lo >> hi >> x; --lo;
		x = (x + last) % 1000000000;
		auto res = sum(t[min(x, X - 1)]);
		last = x * res.f + res.s;
		cout << last << '\n';
	}
}