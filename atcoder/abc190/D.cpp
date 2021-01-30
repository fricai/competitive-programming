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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n; cin >> n;
	ll ans = 0;
	auto  f = [&](ll k) {
		if (k % 2 == 1) return n % k == 0;
		else return (2 * n) / k % 2 == 1;
	};
	for (ll k = 1; k * k <= 2 * n; ++k) {
		if ((2 * n) % k == 0) {
			ans += f(k);
			if (k * k != 2 * n) ans += f(2 * n / k);
		}
	}
	cout << ans;
}