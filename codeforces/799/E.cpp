#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll inf = 1e18;

const int N = 1 << 18;
struct node {
	ll sum; int cnt;
	node() : sum{0}, cnt{0} { }
	node(const node &a, const node &b) : sum{a.sum + b.sum}, cnt{a.cnt + b.cnt} { }
};
node t[N << 1];

vector<int> cmp;

int n;
void build(const vector<int> &a) {
	cmp = a;
	sort(all(cmp));
	cmp.erase(unique(all(cmp)), end(cmp));
	n = sz(cmp);
}

ll get(ll x) {
	assert(t[1].cnt >= x);
	// if (t[1].cnt < x) return inf;
	
	auto rec = [&](auto &&self, int v, int l, int r) -> ll {
		if (x == 0) return 0;
		if (t[v].cnt <= x)
			return x -= t[v].cnt, t[v].sum;
		if (r - l == 1) {
			auto res = x * cmp[l];
			x = 0;
			return res;
		}
		
		int m = (l + r) / 2;
		ll res = self(self, v << 1, l, m);
		res += self(self, v << 1|1, m, r);
		return res;
	};
	return rec(rec, 1, 0, n);
}

void update(ll x, int del) {
	auto rec = [&](auto &&self, int v, int l, int r) -> void {
		if (r - l == 1) {
			t[v].cnt += del;
			t[v].sum = t[v].cnt * x;
			return;
		}
		int m = (l + r) / 2;
		if (x < cmp[m]) self(self, v << 1, l, m);
		else self(self, v << 1|1, m, r);
		t[v] = node(t[v << 1], t[v << 1|1]);
	};
	rec(rec, 1, 0, n);
}
void remove(int x) { update(x, -1); }
void add(int x) { update(x, +1); }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k; cin >> n >> m >> k;
	vector<int> c(n);
	for (auto &x : c) cin >> x;
	build(c);

	vector<int> type(n, 0);
	int a[2];
	for (auto b : {0, 1}) {
		cin >> a[b];
		rep(i, 0, a[b]) {
			int x; cin >> x; --x;
			type[x] |= 1 << b;
		}
	}
	
	array<vector<int>, 4> grp;
	rep(i, 0, n) grp[type[i]].push_back(c[i]);
	for (auto &v : grp) sort(all(v));
	
	ll cur = 0;
	
	int x = min(k, sz(grp[3])), d = min(sz(grp[1]), sz(grp[2]));
	if (k - x > d || m - 2 * k + x < 0)
		return cout << "-1\n", 0;
	
	for (auto x : grp[0])
		add(x);
	for (auto b : {1, 2}) {
		rep(j, 0, k - x)
			cur += grp[b][j];
		rep(j, k - x, sz(grp[b]))
			add(grp[b][j]);
	}
	
	rep(i, 0, x) cur += grp[3][i];
	rep(i, x, sz(grp[3]))
		add(grp[3][i]);

	ll ans = get(m - 2 * k + x) + cur;
	
	for (int y = x - 1, i = k - x + 1;
		y >= 0 && y + 2 * i <= m && i <= d;
		--y, ++i) {
		cur -= grp[3][y];
		add(grp[3][y]);
		for (auto b : {1, 2}) {
			cur += grp[b][i - 1];
			remove(grp[b][i - 1]);
		}
		uin(ans, get(m - y - 2 * i) + cur);
	}
	
	cout << (ans < inf ? ans : -1) << '\n';
}