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

const ll inf = 1e18;
ll mn[1 << 3];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	rep(i, 1, 1 << 3) mn[i] = inf;
	rep(i, 0, n) {
		ll c; cin >> c;
		int S = 0;
		string s; cin >> s;
		for (auto c : s) {
			if (c == 'A') S |= 1 << 0;
			if (c == 'B') S |= 1 << 1;
			if (c == 'C') S |= 1 << 2;
		}
		ckmin(mn[S], c);
	}

	ll ans = inf;
	rep(S, 0, 1 << 8) {
		int cur = 0;
		rep(j, 0, 8) if (S >> j & 1) cur |= j;
		if (cur == 7) {
			ll s = 0;
			rep(j, 0, 8) if (S >> j & 1) s += mn[j];
			ckmin(ans, s);
		}
	}

	cout << (ans < inf ? ans : -1);
}