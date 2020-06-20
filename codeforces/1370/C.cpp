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

bool solve() {
	int n; cin >> n;
	if (n == 1) return 1;
	if (n & 1) return 0;
	if (n == 2) return 0;

	int k = 0;
	while (n % 2 == 0) n /= 2, ++k;
	if (n == 1) return 1;
	if (k > 1) return 0;

	bool prime = true;
	for (int d = 2; 1ll * d * d <= n; ++d)
		if (n % d == 0) prime = false;
	if (prime) return 1;
	return 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "FastestFinger" : "Ashishgup") << '\n';
}