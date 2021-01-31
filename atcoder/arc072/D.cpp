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

ll mex(vector<ll> v) {
	vector<int> vis;
	for (auto x : v) {
		if (sz(vis) <= x) vis.resize(x + 1);
		vis[x] = 1;
	}
	rep(i, 0, sz(vis)) if (!vis[i]) return i;
	return sz(vis);
}

const int B = 30;
ll dp[B][B];

ll f(ll x, ll y) {
	if (dp[x][y] < 0) {
		vector<ll> oth;
		for (int i = 1; 2 * i <= x; ++i) oth.push_back(f(x - 2 * i, y + i));
		for (int i = 1; 2 * i <= y; ++i) oth.push_back(f(x + i, y - 2 * i));
		dp[x][y] = mex(oth);
	}
	return dp[x][y];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// rep(x, 0, B) rep(y, 0, B) dp[x][y] = -1;
	// for (int x = 0; x <= 25; ++x) {
	// 	for (int y = 0; y <= 25; ++y) {
	// 		cout << f(x, y) << '\t';
	// 	}
	// 	cout << '\n';
	// }

	ll x, y; cin >> x >> y;
	cout << (abs(x - y) <= 1 ? "Brown" : "Alice");
}