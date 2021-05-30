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

string solve() {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	for (int j = 0; j < m; ++j) {
		string t = s;
		rep(i, 0, n) {
			if (t[i] == '1') continue;
			int count = 0;
			if (i != 0) count += s[i - 1] == '1';
			if (i + 1 < n) count += s[i + 1] == '1';
			if (count == 1) t[i] = '1';
		}
		if (s == t) break;
		s = t;
	}
	return s;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while (t--) cout << solve() << '\n';
} 