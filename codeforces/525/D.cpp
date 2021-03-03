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

const int N = 1 << 11;
char g[N][N], res[N][N];
int n, m;
bool valid(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }
bool can(int x, int y)  { return valid(x, y) && g[x][y] == '.'; }
bool check(int x, int y) {
	if (can(x, y)) return false;
	for (int a : {-1, +1}) {
		for (int b : {-1, +1}) {
			bool works = true;
			rep(S, 1, 4) works &= can(x + a * (S & 1), y + b * (S >> 1 & 1));
			if (works) return true;
		}
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	rep(i, 0, n) rep(j, 0, m) cin >> g[i][j];
	queue<pair<int, int>> q;
	rep(i, 0, n) rep(j, 0, m) if (check(i, j)) q.push({i, j});
	
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		if (!check(x, y)) continue;
		g[x][y] = '.';
		for (int i : {-1, 0, +1})
			for (int j : {-1, 0, +1})
				q.push({x + i, y + j});
	}
	rep(i, 0, n) cout << g[i] << '\n';
}