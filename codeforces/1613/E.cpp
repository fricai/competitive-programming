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

void solve() {
	int n, m; cin >> n >> m;
	vector<string> g(n);
	for (auto &row : g)
		cin >> row;

	auto check = [&](int i, int j) -> bool {
		return 0 <= i && i < n && 0 <= j && j < m;
	};
	auto empty = [&](int i, int j) -> bool {
		return check(i, j) && g[i][j] == '.';
	};

	auto dfs = [&](const auto &self, int i, int j) -> void {
		if (!check(i, j) || g[i][j] != '.')
			return;
		int paths = empty(i - 1, j) + empty(i, j - 1) + empty(i + 1, j) + empty(i, j + 1);
		if (paths > 1)
			return;
		g[i][j] = '+';
		self(self, i - 1, j);
		self(self, i + 1, j);
		self(self, i, j - 1);
		self(self, i, j + 1);
	};

	int x = -1, y = -1;
	rep(i, 0, n) rep(j, 0, m) if (g[i][j] == 'L') x = i, y = j;
	assert(~x && ~y);
	dfs(dfs, x - 1, y);
	dfs(dfs, x, y + 1);
	dfs(dfs, x + 1, y);
	dfs(dfs, x, y - 1);

	for (auto row : g)
		cout << row << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
