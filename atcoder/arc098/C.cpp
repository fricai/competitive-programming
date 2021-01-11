#include <bits/stdc++.h>
#include <atcoder/all>

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

	int n; cin >> n;
	string s; cin >> s;
	
	int w_l = 0, e_r = 0;
	per(i, 0, n) if (s[i] == 'E') ++e_r;

	int ans = n;
	rep(i, 0, n) {
		if (s[i] == 'E') --e_r;
		ckmin(ans, w_l + e_r);
		if (s[i] == 'W') ++w_l;
	}
	cout << ans;
}