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

int solve() {
	int n; cin >> n;
	vector<string> s(n);
	for (auto &x : s) cin >> x;

	int ans = 0;
	for (int c = 0; c < 5; ++c) {
		vector<int> f(n), g(n);
		rep(i, 0, n) {
			for (auto x : s[i]) {
				if (x == c + 'a')
					++f[i];
				else
					--f[i];
			}
		}
		sort(rall(f));
		int k = 0, cur = 0;
		rep(i, 0, n) {
			cur += f[i];
			if (cur > 0) ++k;
		}
		uax(ans, k);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}