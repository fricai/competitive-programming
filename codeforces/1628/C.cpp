#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int solve() {
	int n; cin >> n;
	vector g(n, vector(n, 0));
	for (auto &row : g)
		for (auto &x : row)
			cin >> x;

	vector par(n, vector(n, 0));
	int res = 0;
	auto choose = [&](int x, int y) {
		if (x > 0) par[x - 1][y] ^= 1;
		if (x + 1 < n) par[x + 1][y] ^= 1;
		if (y > 0) par[x][y - 1] ^= 1;
		if (y + 1 < n) par[x][y + 1] ^= 1;
		res ^= g[x][y];
	};
	rep(i, 1, n)
		rep(j, 0, n)
			if (!par[i - 1][j])
				choose(i, j);
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
