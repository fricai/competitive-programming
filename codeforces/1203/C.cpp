#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	int n; cin >> n;
	long long a[n];
	REP(i, 0, n) cin >> a[i];
	long long g = 0;
	REP(i, 0, n) g = __gcd(g, a[i]);
	long long ans = 0;
	for (long long i = 1; i * i <= g; ++i) 
		if (g % i == 0) { 
			++ans;
			if (g / i != i)
				++ans;
		}
	cout << ans;
}