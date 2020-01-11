#include <iostream>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;

using ll = long long;

signed main() {
	cin.sync_with_stdio(false); cin.tie(nullptr);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	pair<string, int> p[n];
	int ans = 0;
	rep(i, 0, n) cin >> p[i].first >> p[i].second;
	string s; cin >> s;
	bool flag = false;
	rep(i, 0, n) {
		if (flag) ans += p[i].second;
		if (s == p[i].first) flag = true;
	}
	cout << ans;
}