#include <algorithm>
#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a, b; cin >> a >> b;
	cout << a / __gcd(a, b) * b;
}