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

const int N = 1 << 17;
const int inf = 1e9;
struct segtree {
	int t[N << 1];
	segtree() { fill_n(t, N << 1, -inf); }
	int query(int l, int r) {
		int res = -inf;
		for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
			if (l & 1) uax(res, t[l++]);
			if (r & 1) uax(res, t[--r]);
		}
		return res;
	}
	void update(int p, int v) {
		for (uax(t[p += N], v); p >>= 1; )
			t[p] = max(t[p << 1], t[p << 1|1]);
	}
} tc, td;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c, d; cin >> n >> c >> d;
	int ans = 0;
	rep(i, 0, n) {
		int b, p; char type;
		cin >> b >> p >> type;
		if (type == 'C') {
			if (p > c) continue;
			uax(ans, b + max(td.query(0, d + 1), tc.query(0, c - p + 1)));
			tc.update(p, b);
		} else {
			if (p > d) continue;
			uax(ans, b + max(tc.query(0, c + 1), td.query(0, d - p + 1)));
			td.update(p, b);
		}
	}
	cout << ans << '\n';
}