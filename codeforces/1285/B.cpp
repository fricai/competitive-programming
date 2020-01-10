#include <iostream>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = long long;
signed main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll a[n];
		rep(i, 0, n) cin >> a[i];
		ll cur = 0, mx = a[0], sum = 0;
		rep(i, 0, n) sum += a[i];
		bool init = 1, flag = 0;
		rep(i, 0, n) {
			cur = cur + a[i];
			if (cur > mx) {
				mx = cur;
				if (init && i == n - 1)
					flag = 1;
			}
			if (cur <= 0) {
				cur = 0;
				init = 0;
			}
		}

		cout << (flag || sum > mx ? "YES" : "NO") << '\n';
	}
}