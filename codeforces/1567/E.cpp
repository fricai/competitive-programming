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

constexpr int inf = 1e9 + 10;

struct node {
	int f, b, suff, pref, len;
	ll ans;

	node() : f{inf}, b{0}, suff{0}, pref{0}, len{0}, ans{0} { }
	node(int v) : f{v}, b{v}, suff{1}, pref{1}, len{1}, ans{1} { }
};

node operator+(node l, node r) {
	if (l.len == 0)
		return r;
	if (r.len == 0)
		return l;
	node res;

	res.len = l.len + r.len;
	res.f = l.f;
	res.b = r.b;
	res.ans = l.ans + r.ans;

	res.pref = l.pref;
	res.suff = r.suff;

	if (l.b <= r.f) { 
		res.ans += 1ll * l.suff * r.pref;

		if (l.suff == l.len && r.pref == r.len) {
			res.pref = res.suff = res.len; 
		} else if (l.suff == l.len && r.pref != r.len) {
			res.pref = l.len + r.pref;
		} else if (l.suff != l.len && r.pref == r.len) {
			res.suff = l.suff + r.len;
		}
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;

	vector<node> t(n + n);
	auto query = [&](int l, int r) {
		node resl, resr;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) resl = resl + t[l++];
			if (r & 1) resr = t[--r] + resr;
		}
		return resl + resr;
	};
	auto update = [&](int p, int v) {
		for (t[p += n] = v; p >>= 1; )
			t[p] = t[p << 1] + t[p << 1|1];
	};
	rep(i, 0, n) {
		int x; cin >> x;
		update(i, x);
	}

	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int p, v; cin >> p >> v;
			update(p - 1, v);
		} else {
			int l, r; cin >> l >> r;
			cout << query(l - 1, r).ans << '\n';
		}
	}
}
