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

ll sum(ll s, ll n) { return n <= 0 ? 0 : (n * (n - 1)) / 2 + s * n; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a, b, c, d; cin >> a >> b >> c >> d;

	ll ans = 0;
	for (ll z = c; z <= d; ++z) {
		ll l = max(a, z - c + 1), m = z - b + 1;
		ans += (c - b + 1) * max(0ll, b - max(m, l - 1));
		ans += sum(c - max(b, z - l + 1) + 1, min(b, m) - l + 1);
	}
	
	cout << ans;
}