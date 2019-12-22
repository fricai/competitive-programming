#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int a[n];
	REP(i, 0, n) cin >> a[i];
	int cur = 1;
	REP(i, 0, n)
		if (a[i] == cur) ++cur;
	// REP(i, 0, n) cerr << a[i] << ' '; cerr << '\n';
	// cerr << cur;
	if (cur == 1) cout << -1;
	else cout << n - cur + 1;
}