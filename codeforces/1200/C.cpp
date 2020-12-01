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

	ll n, m; int q; cin >> n >> m >> q;
	ll g = gcd(n, m);
	n /= g; m /= g;

	auto f = [&](ll s, short b) {
		if (--b) return (s - 1) / m;
		return (s - 1) / n;
	};
	while (q--) {
		short sx, ex; ll s, e; cin >> sx >> s >> ex >> e;
		s = f(s, sx); e = f(e, ex);
		cout << (s != e ? "NO" : "YES") << '\n';
	}
}