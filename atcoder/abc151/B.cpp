#include <iostream>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define dbg(x) #x << ": " << x <<
#define sz(x) ((int)x.size())

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, m; cin >> n >> k >> m;
	int res = n * m;
	rep(i, 1, n) {
		int x; cin >> x;
		res -= x;
	}
	res = max(0, res);
	cout << (res > k ? -1 : res);
}