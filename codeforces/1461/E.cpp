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

const int N = 1 << 20;
bool vis[N];

bool solve() {
	ll k, l, r, t, x, y; cin >> k >> l >> r >> t >> x >> y;
	if (k < l || k > r) return 0;
	if (x > y) {
		if (k + y > r) k -= x, --t;
		if (k < l) return 0;
		if ((k - l) / (x - y) < t) return 0;
		return 1;
	}

	while (t > 0) {
		if (vis[k % x]) return 1;
		vis[k % x] = 1;
		ll n = (k - l) / x;
		t -= n; k -= n * x;
		if (t <= 0) return true;
		if (k + y > r) return false;
		k += y - x; --t;
		if (k < l) return false;
		if (t <= 0) return true;
	}
	return 1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cout << (solve() ? "Yes" : "No") << '\n';	
}