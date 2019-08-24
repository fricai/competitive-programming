#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	int M, D; cin >> M >> D;
	int ans = 0;
	REP(m, 1, M + 1)
		REP(d, 1, D + 1) {
			int d1 = d % 10, d10 = d/10 % 10;
			if (d1 > 1 && d10 > 1 && d1 * d10 == m)
				++ans; 
		}
	cout << ans;
}