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

constexpr int inf = 1e9;

struct T {
	int n;
	vector<int> t;

	T() { }
	T(int n) : n{n}, t(n + n, -1) { }
	int query(int l, int r) {
		int res = -1;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) uax(res, t[l++]);
			if (r & 1) uax(res, t[--r]);
		}
		return res;
	}
	void update(int p, int x) {
		for (t[p += n] = x; p >>= 1; )
			t[p] = max(t[p << 1], t[p << 1|1]);
	}
};

ll solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;
	vector<int> p(n + 1);
	for (int i = 0; i < n; ++i) {
		if (i & 1) {
			p[i + 1] = p[i] - a[i];
		} else {
			p[i + 1] = p[i] + a[i];
		}
	}

	auto cmp = p;
	sort(all(cmp));
	for (auto &x : p) {
		x = lower_bound(all(cmp), x) - begin(cmp);
	}

	T t[2]; t[0] = T(n + 1); t[1] = T(n + 1);

	vector<vector<int>> st(n + 1);

	ll ans = 0;
	for (int r = 0; r < n; ++r) {
	 	st[p[r]].push_back(r);
		t[r & 1].update(p[r], r);
		int i = max(t[0].query(p[r + 1] + 1, n + 1), t[1].query(0, p[r + 1]));
	 	ans += end(st[p[r + 1]]) - upper_bound(all(st[p[r + 1]]), i);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
