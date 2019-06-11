#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int rem[3]; rem[0] = rem[1] = rem[2] = 0;
		REP(i, 0, n) {
			int a;
			cin >> a;
			++rem[a % 3];
		}
		cout << rem[0] + (rem[1] + rem[2] + min(rem[1], rem[2]))/3 << '\n';
	}
}
