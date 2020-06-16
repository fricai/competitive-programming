#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int solve() {
	int n, k; cin >> n >> k;
	
	int mn = n;
	for (int d = 1; d * d <= n; ++d) {
		if (n % d == 0) {
			if (d <= k) ckmin(mn, n / d);
			if (n / d <= k) ckmin(mn, d);
		}
	}
	return mn;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}