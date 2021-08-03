#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k; cin >> n >> m >> k;

	vector<string> g(n);
	for (auto &row : g)
		cin >> row;
	vector vis(n, vector(m, false));

	auto dfs = [&](const auto &self, int i, int j) -> void {
		if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || g[i][j] != '.')
			return;
		vis[i][j] = true;
		self(self, i + 1, j);
		self(self, i - 1, j);
		self(self, i, j + 1);
		self(self, i, j - 1);
		if (k > 0) {
			--k;
			g[i][j] = 'X';
		}
	};
	rep(i, 0, n) rep(j, 0, m) dfs(dfs, i, j);
	for (auto row : g)
		cout << row << '\n';
}