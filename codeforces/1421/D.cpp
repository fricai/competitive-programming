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

using point = complex<int>;
const int X = 6;
const point dir[X] = {
	{1, 1}, {0, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, 0}
};
ll c[X];

ll solve() {
	ll x, y; cin >> x >> y;
	rep(i, 0, X) cin >> c[i];
	rep(i, 0, X)
		rep(j, 0, X)
			rep(k, 0, X)
				if (dir[i] + dir[j] == dir[k])
					ckmin(c[k], c[i] + c[j]);
	if (x >= 0 && y >= 0) {
		ll z = min(x, y);
		x -= z;
		y -= z;
		return c[0] * z + c[1] * y + c[5] * x;
	}
	if (x >= 0 && y <= 0) {
		y = -y;
		return c[4] * y + c[5] * x;
	}
	if (x <= 0 && y >= 0) {
		x = -x;
		return c[1] * y + c[2] * x;
	}
	if (x <= 0 && y <= 0) {
		x = -x;
		y = -y;
		ll z = min(x, y);
		x -= z;
		y -= z;
		return c[4] * y + c[2] * x + c[3] * z;
	}
	return -1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}