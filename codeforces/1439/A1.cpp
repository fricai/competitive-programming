#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		vector<vector<int>> op;

		int n, m; cin >> n >> m;
		rep(i, 0, n) {
			rep(j, 0, m) {
				char x; cin >> x;
				if (x == '1') {
					int s = i + 1, t = j + 1;
					if (s == n) s = i - 1;
					if (t == m) t = j - 1;
					op.push_back({i, j, s, t, i, t});
					op.push_back({i, j, s, j, i, t});
					op.push_back({i, j, s, t, s, j});
				}
			}
		}

		cout << sz(op) << '\n';
		for (auto v : op) {
			for (auto x : v) cout << x + 1 << ' ';
			cout << '\n';
		}
	}
}