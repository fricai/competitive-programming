#include <algorithm>
#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

#define debug(x) cerr << #x << ' ' << (x) << '\n'
#define sz(x) (int)(x).size()

using ll = long long;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
	int mx = 0;
	for (int j = 0; j <= d; ++j)
		mx = max(mx, f * min({b, c, j}) + e * min(a, d - j));
	cout << mx;
}