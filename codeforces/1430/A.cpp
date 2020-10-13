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

void solve() {
	int n; cin >> n;
	for (int c = 0; c <= n / 7; ++c)
		for (int b = 0; b <= (n - 7 * c) / 5; ++b) {
			int a = n - 7 * c - 5 * b;
			if (a >= 0 && a % 3 == 0) return void(cout << a / 3 << ' ' << b << ' ' << c << '\n');
		}
	return void(cout << -1 << '\n');
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}