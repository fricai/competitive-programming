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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x; cin >> x;

	int L = x;
	int y = x;
	for (int d = 2; d * d <= y; ++d) {
		if (y % d) continue;
		while (y % d == 0) y /= d;
		uin(L, x - d + 1);
	}
	if (y > 1) uin(L, x - y + 1);
	
	int ans = x;
	for (int a = L; a <= x; ++a) {
		int y = a;
		for (int d = 2; d * d <= y; ++d) {
			if (y % d) continue;
			while (y % d == 0) y /= d;
			uin(ans, a - d + 1);
		}
		if (y != a) uin(ans, a - y + 1);
	}
	cout << ans << '\n';
}