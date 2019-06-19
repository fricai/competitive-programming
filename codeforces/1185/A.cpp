#include <algorithm>
#include <iostream>
using namespace std;

signed main() {
	long long p[3], d; cin >> p[0] >> p [1] >> p[2] >> d;
	sort(p, p + 3);
	long long ans = 0;
	if (p[1] - p[0] < d) ans += d - (p[1] - p[0]);
	if (p[2] - p[1] < d) ans += d - (p[2] - p[1]);
	cout << ans;
}
