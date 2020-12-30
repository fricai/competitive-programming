#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 19, B = 60, M = 1e9 + 7;

ll x[N], f[B], or_sum[N], g[B];

template<class T> void add(T &a, T b) { a += b; if (M <= a) a -= M; }

int solve() {
	int n; cin >> n;
	rep(i, 0, n) cin >> x[i];

	

	rep(j, 0, B) {
		f[j] = 0;
		rep(i, 0, n) if (x[i] >> j & 1) ++f[j];
	}

	rep(i, 0, n) {
		or_sum[i] = 0;
		per(j, 0, B) {
			add(or_sum[i], (x[i] >> j & 1) ? n : f[j]);
			if (j) add(or_sum[i], or_sum[i]);
		}
		// cerr << or_sum[i] << ' ';
	}
	// cerr << '\n';

	rep(j, 0, B) {
		g[j] = 0;
		rep(i, 0, n) if (x[i] >> j & 1) add(g[j], or_sum[i]);
	}

	ll res = 0;
	rep(i, 0, n) {
		ll cur = 0;
		per(j, 0, B) {
			add(cur, (x[i] >> j & 1) ? g[j] : 0ll);
			if (j) add(cur, cur);
		}
		add(res, cur);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}