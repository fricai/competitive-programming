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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;

const ll inf = 1e18;
struct S {
	ll t[N << 1], lz[N << 1];

	S() {
		// t.resize(2 * N, -inf);
		// lz.resize(2 * N, 0);
		fill_n(t, 2 * N, inf);
		fill_n(lz, 2 * N, 0);
	}

	void push(int v) {
		t[v] += lz[v];
		if (t[v] > inf) t[v] = inf;
		if (v < N) {
			lz[v << 1|0] += lz[v];
			lz[v << 1|1] += lz[v];
		}
		lz[v] = 0;

	}

	int lo, hi;
	ll x;

	void upd(int v, int l, int r) {
		push(v);
		if (hi <= l || r <= lo) return;
		if (lo <= l && r <= hi) return lz[v] += x, push(v);
		int m = (l + r) / 2;
		upd(v << 1, l, m); upd(v << 1|1, m, r);
		t[v] = min(t[v << 1], t[v << 1|1]);
	}

	void add(int l, int r, ll v) {
		lo = l; hi = r; x = v;
		upd(1, 0, N);
	}

	ll query(int v, int l, int r) {
		push(v);
		if (hi <= l || r <= lo) return inf;
		if (lo <= l && r <= hi) return t[v];
		int m = (l + r) / 2;
		return min(query(v << 1, l, m),query(v << 1|1, m, r));
	}

	ll query(int l, int r) {
		lo = l; hi = r;
		return query(1, 0, N);
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, a, b; cin >> n >> q >> a >> b; --a; --b;
	S plus, minus;

	int x; cin >> x; --x;

	plus.add(a, a + 1, -inf + abs(b - x) + a);
	if (a != b) plus.add(b, b + 1, -inf + abs(a - x) + b);	

	minus.add(a, a + 1, -inf + abs(b - x) - a);
	if (a != b) minus.add(b, b + 1, -inf + abs(a - x) - b);

	rep(i, 1, q) {
		int y; cin >> y; --y;

		ll to_place = min(minus.query(0, y) + y, plus.query(y, n) - y);

		plus.add(0, n, abs(x - y));
		minus.add(0, n, abs(x - y));

		// dp(i, x) = min(dp(i - 1, x) + |x - y|, min(dp(i - 1, z) + |z - y|))
		ll dpix = plus.query(x, x + 1) - x;
		if (dpix > to_place) {
			plus.add(x, x + 1, to_place - dpix);
			minus.add(x, x + 1, to_place - x - minus.query(x, x + 1));
		}

		x = y;
	}
	
	ll ans = inf;
	rep(i, 0, n) ckmin(ans, plus.query(i, i + 1) - i);
	cout << ans;
}