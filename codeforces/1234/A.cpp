#include <bits/stdc++.h>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q;
	while(q--) {
		long long n; cin >> n;
		long long ans = n - 1;
		REP(i, 0, n) {
			int x; cin >> x;
			ans += x;
		}
		cout << ans / n << '\n';
	}
}