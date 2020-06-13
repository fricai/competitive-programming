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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int a[2 * n]; rep(i, 0, 2 * n) cin >> a[i];
	sort(a, a + 2 * n);
	int s1 = 0, s2 = 0;
	rep(i, 0, n) s1 += a[i], s2 += a[i + n];
	if (s1 == s2) return cout << -1, 0;
	rep(i, 0, 2 * n) cout << a[i] << ' ';
}