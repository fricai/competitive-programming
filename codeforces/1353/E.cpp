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

int solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	
	int tot = 0;
	rep(i, 0, n) if (s[i] == '1') ++tot;

	int ans = n;
	rep(i, 0, k) {
		int cur = 0, res = 0;
		for (int j = i; j < n; j += k) {
			cur += (s[j] == '1' ? +1 : -1);
			if (cur < 0) cur = 0;
			else ckmax(res, cur);
		}
		ckmin(ans, tot - res);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}