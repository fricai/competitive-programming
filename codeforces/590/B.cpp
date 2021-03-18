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

const int inf = 1e9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll x1, x2, y1, y2, v, t, vx, vy, wx, wy;
	cin >> x1 >> y1 >> x2 >> y2 >> v >> t >> vx >> vy >> wx >> wy;

	ll x = x2 - x1, y = y2 - y1;

	ld l = 0, r = inf;
	rep(i, 0, 1 << 7) {
		ld m = (l + r) / 2;
		ld cur_x, cur_y;
		if (m < t) cur_x = m * vx, cur_y = m * vy;
		else cur_x = t * vx + (m - t) * wx, cur_y = t * vy + (m - t) * wy;
		(hypotl(cur_x - x, cur_y - y) < v * m ? r : l) = m;
	}
	
	cout << fixed << setprecision(10) << r << '\n';
}