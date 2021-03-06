#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr ll inf = 1e18;

struct max_segtree {
	int n;
	vector<ll> t;
	max_segtree(int n) : n{n}, t(2 * n, -inf) { }
	ll query(int l, int r) {
		if (l >= r) return -inf;
		ll res = -inf;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = max(res, t[l++]);
			if (r & 1) res = max(res, t[--r]);
		}
		return res;
	}
	void update(int p, ll x) {
		for (t[p += n] = x; p >>= 1; )
			t[p] = max(t[p << 1], t[p << 1|1]);
	}
};

int solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;
	ll x; cin >> x;

	vector<ll> dp(n);
	max_segtree fst(n);
	auto f = [&](int j) -> ll {
		return j <= 0 ? 0ll : fst.query(0, j);
	};


	for (auto &y : a)
		y -= x;
	vector<ll> p(n + 1);
	for (int i = 0; i < n; ++i)
		p[i + 1] = p[i] + a[i];
	max_segtree sec(n + 1);
	for (int i = 0; i <= n; ++i)
		sec.update(i, -p[i]);
	auto mn = [&](int l, int r) -> ll { // return min p[i] for i in [l, r)
		return -sec.query(l, r);
	};

	vector<int> lef(n);
	for (int i = n - 1, j = n - 1; i >= 0; --i) {
		j = min(i - 1, j);
		while (j >= 0 && mn(j + 2, i + 2) >= p[j])
			--j;
		lef[i] = j;
	}

	max_segtree thr(n);
	auto query = [&](int x, int y) -> ll {
		if (x == -1) return max(1ll, thr.query(0, y));
		return thr.query(x, y);
	};
	for (int i = 0; i < n; ++i) {
		dp[i] = 1 + f(i - 1);
		uax(dp[i], i + query(lef[i], i - 1));
		thr.update(i, f(i) - i);
		fst.update(i, dp[i]);
	}
	return f(n);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
