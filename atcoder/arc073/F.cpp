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
	ll t[N << 1];
	S() { fill_n(t, 2 * N, inf); }
	void set(int p, ll v) {
		for (t[p |= N] = v; p >>= 1; )
			t[p] = min(t[p << 1], t[p << 1|1]);
	}
	ll query(int l, int r) {
		ll res = inf;
		for (l |= N, r |= N; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ckmin(res, t[l++]);
			if (r & 1) ckmin(res, t[--r]);
		}
		return res;
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, a, b; cin >> n >> q >> a >> b; --a; --b;
	S plus, minus;

	int x; cin >> x; --x;

	plus.set(a, abs(b - x) + a);
	plus.set(b, abs(a - x) + b);
	minus.set(a, abs(b - x) - a);
	minus.set(b, abs(a - x) - b);
	ll shift = 0;
	
	rep(i, 1, q) {
		int y; cin >> y; --y;
		ll to_place = min(minus.query(0, y) + y, plus.query(y, n) - y) - abs(x - y);
		shift += abs(x - y);
		ll dpix = plus.query(x, x + 1) - x;
		if (dpix > to_place) {
			plus.set(x, to_place + x);
			minus.set(x, to_place - x);
		}
		x = y;
	}

	ll ans = inf;
	rep(i, 0, n) ckmin(ans, plus.query(i, i + 1) - i);
	cout << ans + shift;
}