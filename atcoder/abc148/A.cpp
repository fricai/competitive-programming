#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b; cin >> a >> b;
	cout << 1 + 2 + 3 - a - b;
}