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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool solve() {
	string s; cin >> s;
	string t; cin >> t;

	int n = sz(s), m = sz(t);
	for (int r = 0; r < n; ++r) {
		int l = m - r - 1;
		if (l < 0) continue;
		
		for (int i = 0; i < n; ++i) {
			int p = i;
			string res = string(1, s[p]);
			
			for (int j = 0; j < r; ++j) {
				++p;
				if (p == n) {
					res.push_back('#');
					break;
				}
				res.push_back(s[p]);
			}
			
			for (int j = 0; j < l; ++j) {
				--p;
				if (p == -1 || p == n) {
					res.push_back('#');
					break;
				}
				res.push_back(s[p]);
			}
			if (res == t)
				return 1;
		}
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q;
	while (q--) cout << (solve() ? "YES" : "NO") << '\n';
}