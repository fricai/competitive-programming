#include <iostream>
#include <map>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> m;
		REP(i, 0, n) {
			int x; cin >> x;
			int p = x&(-x), b = 8 * sizeof(int) - __builtin_clz(p) - 1;
			m[x / p] = max(m[x / p], b);
		}
		
		int ans = 0;
		for (auto x : m) ans += x.second;
		cout << ans << '\n';
	}
}