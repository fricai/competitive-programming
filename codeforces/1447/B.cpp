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
	cin.tie(nullptr)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		bool neg = 0;
		int s = 0, mn = 101;
		rep(i, 0, n) rep(j, 0, m) {
			int x; cin >> x;
			ckmin(mn, abs(x));
			s += abs(x);
			if (x < 0) neg ^= 1;
		}
		if (neg) s -= 2 * mn;
		cout << s << '\n';
	}
}