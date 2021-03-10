#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> A, B;
		rep(i, 0, 2 * n) {
			int x, y; cin >> x >> y;
			if (x == 0) A.push_back(abs(y));
			else B.push_back(abs(x));
		}
		sort(all(A)); sort(all(B));

		ld res = 0;
		rep(i, 0, n) res += hypotl(A[i], B[i]);
		cout << fixed << setprecision(12) << res << '\n';
	}
}