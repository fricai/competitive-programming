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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		string s; cin >> s;
		ll ans = 0;
		for (int p = -1e5, i = 0, j = 0; i < sz(s); i = j) {
			if (s[i] == '0') { ++j; continue; }
			while (j < sz(s) && s[j] == '1') ++j;
			ans += min(b * (i - p), a);
			p = j;
		}
		cout << ans << '\n';
	}
}