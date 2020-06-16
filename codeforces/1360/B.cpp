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


const int N = 1 << 6;
int s[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		rep(i, 0, n) cin >> s[i];
		sort(s, s + n);
		int ans = 1e9;
		rep(i, 1, n) ckmin(ans, s[i] - s[i - 1]);
		cout << ans << '\n';
	}
}