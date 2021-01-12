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

	string s; cin >> s;
	rep(i, 1, sz(s)) if (s[i] == s[i - 1]) return cout << i << ' ' << i + 1 << '\n', 0;
	rep(i, 0, sz(s) - 2) {
		string t = s.substr(i, 3);
		sort(all(t));
		if (t[0] == t[1] || t[1] == t[2]) return cout << i + 1 << ' ' << i + 3 << '\n', 0;
	}
	cout << "-1 -1\n";
}