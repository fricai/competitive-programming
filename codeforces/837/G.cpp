// TLEs
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

const int X = 2e5 + 5, N = 75005;

template<class T> pair<T, T> operator+(pair<T, T> a, pair<T, T> b) {
	return {a.first + b.first, a.second + b.second};
}

using ll = int64_t;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using ptr = struct S*;
int n;
struct S {
	pll x; ptr l, r;
	S(pll x = {0, 0}) : x{x}, l{nullptr}, r{nullptr} { }
	S(ptr l, ptr r) : x{l->x + r->x}, l{l}, r{r} { }
};

int lo, hi;
pll sum(ptr v, int l = 0, int r = n) {
	if (hi <= l || r <= lo) return {0, 0};
	if (lo <= l && r <= hi) return v->x;
	int m = l + r >> 1;
	return sum(v->l, l, m) + sum(v->r, m, r);
}

pii y1[N], a[N], y2[N];
vector<int> ord1[X], ord2[X];
ptr t[X];

ptr build(pii y[], int l = 0, int r = n) {
	if (r - l == 1) return new S(y[l]);
	int m = l + r >> 1;
	return new S(build(y, l, m), build(y, m, r));
}

pii *y;
template<class T> void insert(ptr &v, T s, T e, pii a[]) {
	y = a; v = insert(v, s, e, 0, n);
}
template<class T> ptr insert(ptr v, T s, T e, int l, int r) {
	if (e == s) return v;
	if (r - l == 1) return new S(y[l]);
	int m = l + r >> 1;
	T b = lower_bound(s, e, m);
	return new S(insert(v->l, s, b, l, m), insert(v->r, b, e, m, r));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x1, x2;
		cin >> x1 >> x2; ++x1; ++x2;
		ord1[x1].push_back(i);
		ord2[x2].push_back(i);
		cin >> y1[i].second >> a[i].first >> a[i].second >> y2[i].second;
	}

	t[0] = build(y1);
	for (int x = 1; x < X; ++x) {
		t[x] = t[x - 1];
		insert(t[x], all(ord1[x]), a);
		insert(t[x], all(ord2[x]), y2);
	}

	int q; cin >> q; ll last = 0;
	while (q--) {
		int x; cin >> lo >> hi >> x; --lo;
		x = (x + last) % 1000000000;
		auto res = sum(t[min(x, X - 1)]);
		last = x * res.first + res.second;
		cout << last << '\n';
	}
}