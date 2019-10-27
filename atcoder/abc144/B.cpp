#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	bool flag = false;
	REP(i, 1, 10)
		if (n % i == 0 && n / i < 10) flag = true;
	cout << (flag ? "Yes" : "No");
}