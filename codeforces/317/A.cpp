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

ll m;
ll f(ll x, ll y) {
	if (x < y) swap(x, y);
	if (x >= m) return 0;
	auto res = f(x + y, x);
	return res < 0 ? -1 : 1 + res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll x, y; cin >> x >> y >> m;
	if (x < y) swap(x, y);
	if (x >= m) return cout << 0, 0;
	if (x <= 0) return cout << "-1\n", 0;
	ll k = 0;
	if (y <= 0) {
		k = (x - y - 1) / x;
		y += k * x;
		assert(y >= 0);
	}
	cout << k + f(x, y) << '\n';
}