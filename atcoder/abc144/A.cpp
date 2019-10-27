#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b; cin >> a >> b;
	if (a > 9 || b > 9 || a < 1 || b < 1) cout << -1;
	else cout << a * b; 
}