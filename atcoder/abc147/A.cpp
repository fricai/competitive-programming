#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, y, z; cin >> x >> y >> z;
	cout << (x + y + z < 22 ? "win" : "bust");
}
