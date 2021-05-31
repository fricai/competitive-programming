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

const int X = 1 << 20;
bool dp[X];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v;
	for (int p = 11; p < X; p = 10 * p + 1) {
		v.push_back(p);
	}
	dp[0] = 1;
	rep(i, 1, X) {
		for (auto x : v) {
			if (x > i) break;
			dp[i] |= dp[i - x];
		}
	}

	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		cout << (x <= X && !dp[x] ? "NO" : "YES") << '\n';
	}
}