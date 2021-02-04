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

ll f(ll h, ll w) {
	ll res = inf;
	if (w > 2) res = w % 3 == 0 ? 0 : h;
	rep(x, 1, w) {
		vector<ll> v(3);
		v[0] = h / 2 * x;
		v[1] = (h + 1) / 2 * x;
		v[2] = h * (w - x);
		sort(all(v));
		ckmin(res, v[2] - v[0]);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int h, w; cin >> h >> w;
	cout << min(f(h, w), f(w, h));
}