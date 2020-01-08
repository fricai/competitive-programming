#include <iostream>
#include <sstream>
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;

const int N = 1 << 18;
const ll inf = 1e16;
int n, a[N];

using pnode = struct node*;
struct node {
	static pnode nil;
	ll v, u;
	pnode l, r;
	node(ll a = inf, ll b = inf) : v{a}, u{b}, l{nil}, r{nil} { }
	node(pnode a, pnode b) : l{a}, r{b}, v{min(a->v, b->v)}, u{inf} {	}

	void apply(int val) {
		v += val;
		if (u != inf) u += val;
		else u = val;
	}

	void push() {
		if (u != inf) {
			l->apply(u);
			r->apply(u);
			u = inf;
		}
	}

	void update(int val, int lo, int hi, int st = 0, int en = n - 1) {
		if (st == lo && en == hi) {
			apply(val);
			// cerr << st << ' ' << en << ' ' << v << ' ' << u << '\n';
			return;
		}
		push();
		int m = (st + en) / 2;
		if (hi <= m) l->update(val, lo, hi, st, m);
		else if (lo > m) r->update(val, lo, hi, m + 1, en);
		else {
			l->update(val, lo, m, st, m);
			r->update(val, m + 1, hi, m + 1, en);
		}
		v = min(l->v, r->v);
		u = inf;
	}

	ll query(int lo, int hi, int st = 0, int en = n - 1) {
		if (st == lo && en == hi) return v;
		push();
		int m = (st + en) / 2;
		if (hi <= m) return l->query(lo, hi, st, m);
		if (lo  > m) return r->query(lo, hi, m + 1, en);
		return min(l->query(lo, m, st, m), r->query(m + 1, hi, m + 1, en));
	}

	void inc(int val, int l, int r) {
		if (l > r) {
			update(val, l, n - 1);
			update(val, 0, r);
		}	else update(val, l, r);
	}

	ll rmq(int l, int r) {
		if (l > r)
			return min(query(l, n - 1), query(0, r));
		else
			return query(l, r);
	}

	static pnode build(int st = 0, int en = n - 1) {
		if (st == en) return new node(a[st]);
		int m = (st + en) / 2;
		return new node(build(st, m), build(m + 1, en));
	}
};
pnode node::nil;
pnode root;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	node::nil = new node(); node::nil->l = node::nil->r = node::nil;
	
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	root = node::build();
	int q; cin >> q; cin.get();
	while (q--) {
		string s; getline(cin, s);
		stringstream iss(s);
		int l, r, v; iss >> l >> r;
		if (iss >> v) root->inc(v, l, r);
		else cout << root->rmq(l, r) << '\n';
	}
}