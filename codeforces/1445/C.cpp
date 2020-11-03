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


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		ll p; int q; cin >> p >> q;
		if (p % q != 0) cout << p << '\n';
		else {
			ll x = 1;
			auto f = [&](int d) {
				if (d <= 1) return;
				ll z = p;
				while (z % d == 0) {
					z /= d;
					if (z % q != 0) ckmax(x, z);
				}
			};
			for (int d = 1; d * d <= q; ++d) f(d), f(q / d);
			cout << x << '\n';
		}
	}
}