#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int cnt = 0;
		REP(d, 1, 10) {
			int p = 10;
			while (d * (p - 1) / 9 <= n) {
				++cnt;
				p *= 10;
			}
		}
		cout << cnt << '\n';
	}
}