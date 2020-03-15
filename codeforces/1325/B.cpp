#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(x, v) for (auto &x : v)

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		trav(x, a) cin >> x;
		sort(all(a)); a.erase(unique(all(a)), end(a));
		cout << sz(a) << '\n';
	}
}