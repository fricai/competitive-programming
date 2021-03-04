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

const int N = 1 << 17;
const ll inf = 1e18;

struct tree {
	ll t[N << 1];

	void modify(int l, int r, int value) {
		for (l |= N, r |= N; l < r; l >>= 1, r >>= 1) {
			if (l & 1) t[l++] += value;
			if (r & 1) t[--r] += value;
		}
	}

	ll query(int p) {
		ll res = 0;
		for (p |= N; p; p >>= 1) res += t[p];
		return res;
	}
} A, B;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	rep(i, 1, n) {
		int l = a[i - 1], r = a[i];
		if (l < r) {
			A.modify(1, l + 1, r - l);
			B.modify(1, l + 1, 0);

			A.modify(l + 1, r + 1, r + 1);
			B.modify(l + 1, r + 1, 1);

			A.modify(r + 1, m + 1, r - l);
			B.modify(r + 1, m + 1, 0);
		} else {
			A.modify(1, r + 1, r + 1);
			B.modify(1, r + 1, 1);

			A.modify(r + 1, l + 1, m + r - l);
			B.modify(r + 1, l + 1, 0);
			
			A.modify(l + 1, m + 1, r + m + 1);
			B.modify(l + 1, m + 1, 1);
		}
	}

	ll ans = inf;
	for (int x = 1; x <= m; ++x) ckmin(ans, A.query(x) - B.query(x) * x);
	cout << ans;
}