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

int solve() {
	string s; cin >> s;
	int one = 0, two = 0, ans = 0;
	for (auto x : s) {
		if (x == '(') ++one;
		if (x == '[') ++two;
		if (x == ')' && one > 0) --one, ++ans;
		if (x == ']' && two > 0) --two, ++ans;
	}
	return ans;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}