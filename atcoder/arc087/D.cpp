#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int X = 16e3 + 20;
using bs = bitset<2 * X + 1>;

bool solve(vector<int> f, int x) {
	// x in [-X, +X] -> x + X in [0, 2X]
	int n = sz(f);
	vector<bs> dp(2);
	dp[0][X] = true;
	for (int i = 0; i < n; ++i)
		dp[~i & 1] = dp[i & 1] << f[i] | dp[i & 1] >> f[i];
	return dp[n & 1][x + X];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; int x, y; cin >> s >> x >> y;

	vector<int> f;
	int count = 0;
	for (int i = 0; i < sz(s); ++i) {
		if (s[i] == 'T') {
			f.push_back(count);
			count = 0;
		} else {
			++count;
		}
	}
	f.push_back(count);

	vector<int> a, b;
	for (int i = 2; i < sz(f); i += 2) {
		a.push_back(f[i]);
	}
	for (int i = 1; i < sz(f); i += 2) {
		b.push_back(f[i]);
	}

	cout << (solve(a, x - f[0]) && solve(b, y) ? "Yes" : "No") << '\n';
}
