#include <iostream>
#include <vector>
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

int n;
using pnode = struct node*;
pnode nil;
struct node {
	int v;
	pnode l, r;
	node(int a = 0) : v{a}, l{nil}, r{nil} { }
	node(pnode a, pnode b) : l{a}, r{b}, v{a->v + b->v} { }

	pnode insert(int p, int st = 0, int en = n - 1) {
		if (st == en) return new node(v + 1);
		int m = (st + en) / 2;
		if (p <= m) return new node(l->insert(p, st, m), r);
		else return new node(l, r->insert(p, m + 1, en));
	}

	int query(int lo, int hi, int st = 0, int en = n - 1) {
		if (st == lo && en == hi) return v;
		int m = (st + en) / 2;
		if (hi <= m) return l->query(lo, hi, st, m);
		if (lo  > m) return r->query(lo, hi, m + 1, en);
		return l->query(lo, m, st, m) + r->query(m + 1, hi, m + 1, en);
	}
};

const int N = 1 << 17, A = 1 << 17;
int a[N];
vector<int> p[A];
pnode t[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	nil = new node(); nil->l = nil->r = nil;

	int k; cin >> n >> k; rep(i, 0, n) cin >> a[i + 1];

	t[0] = nil;
	rep(i, 0, n) {
		auto &x = p[a[i + 1]];
		int y = x.size() - k;
		t[i + 1] = t[i]->insert((y < 0 ? 0 : x[x.size() - k]));
		x.push_back(i + 1);
	}

	int q, lst = 0; cin >> q;
	while (q--) {
		int x, y; cin >> x >> y;
		int l = (x + lst) % n + 1, r = (y + lst) % n + 1;
		if (l > r) swap(l, r);
		lst = t[r]->query(0, l - 1) - t[l - 1]->query(0, l - 1);
		cout << lst << '\n';
	}
}