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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w; cin >> h >> w;
	vector c(h, vector(w, 0));
	rep(i, 0, h) {
		string row; cin >> row;
		rep(j, 0, w) c[i][j] = row[j] == '#';
	}
	auto chk = [&](int x, int y) { return 0 <= x && x < h && 0 <= y && y < w; };

	vector vis(h, vector(w, false));
	int ans = 0;
	auto solve = [&](const auto &dfs, int x, int y) -> void {
		if (!chk(x, y) || c[x][y] || vis[x][y])
			return;
		uax(ans, x + y + 1);
		vis[x][y] = true;
		dfs(dfs, x + 1, y);
		dfs(dfs, x, y + 1);
	};
	solve(solve, 0, 0);
	cout << ans << '\n';
}
