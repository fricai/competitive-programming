#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
struct node {
	int dep;
	int maxdep;
	int mindep;
	int ldiff;
	int rdiff;
	int diameter;
	
	void set_leaf() {
		maxdep = dep;
		mindep = dep;
		ldiff = -dep; // max(d(u) - 2 * d(v)), u <= v
		rdiff = -dep; // max(-2 * d(v) + d(w)), v <= w
		diameter = 0; // max(d(u) - 2 * d(v) + d(w)) u <= v <= w
	}
} t[N << 1];

node operator+(const node &l, node r) {
	node c;
	
	r.dep += l.dep;
	r.maxdep += l.dep;
	r.mindep += l.dep;
	r.ldiff -= l.dep;
	r.rdiff -= l.dep;

	c.dep = r.dep;
	c.maxdep = max(l.maxdep, r.maxdep);
	c.mindep = min(l.mindep, r.mindep);

	// u, v both in L; u in L, v in R; u, v in R
	c.ldiff = max({
		l.ldiff,
		l.maxdep - 2 * r.mindep,
		r.ldiff
	});

	// v, w in R; v in L, w in R; v, w in R
	c.rdiff = max({
		l.rdiff,
		-2 * l.mindep + r.maxdep,
		r.rdiff
	});

	// u, v, w in L; u, v in L, w in R; u in L, v, w in R; u, v, w in R
	c.diameter = max({
		l.diameter,
		l.ldiff + r.maxdep,
		l.maxdep + r.rdiff,
		r.diameter
	});

	return c;
}

int n;
void build(int m) {
	n = m;
	auto rec = [&](auto &&self, int v, int l, int r) {
		if (r - l == 1) {
			t[v].dep = 1;
			t[v].set_leaf();
			return;
		}
		int m = (l + r) / 2;
		self(self, v << 1|0, l, m);
		self(self, v << 1|1, m, r);
		t[v] = t[v << 1] + t[v << 1|1];
	};
	rec(rec, 1, 0, n);
}

void flip(int p) {
	auto rec = [&](auto &&self, int v, int l, int r) {
		if (r - l == 1) {
			assert(l == p);
			t[v].dep *= -1;
			t[v].set_leaf();
			return;
		}
		int m = (l + r) / 2;
		if (p < m)
			self(self, v << 1|0, l, m);
		else
			self(self, v << 1|1, m, r);
		t[v] = t[v << 1] + t[v << 1|1];
	};
	rec(rec, 1, 0, n);
}

int get() {
	assert(t[1].dep == 0);
	return t[1].diameter;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	build(2 * (n - 1));
	string s; cin >> s;
	rep(i, 0, 2 * (n - 1))
		if (s[i] == ')')
			flip(i);
	
	cout << get() << '\n';
	while (q--) {
		int u, v; cin >> u >> v; --u; --v;
		if (s[u] != s[v]) {
			flip(u); flip(v);
			swap(s[u], s[v]);
		}
		cout << get() << '\n';
	}
}