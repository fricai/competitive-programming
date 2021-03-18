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

const int N = 1 << 10, inf = 1e9;
char g[N][N];
int d[3][N][N];
int cur = 0;
int n, m;

bool valid(int a, int b) { return 0 <= a && a < n && 0 <= b && b < m; }

void bfs(char c) {
	deque<pair<int, int>> q;
	rep(i, 0, n) rep(j, 0, m) d[cur][i][j] = inf;
	rep(i, 0, n) rep(j, 0, m)
		if (g[i][j] == c) {
			q.push_front({i, j});
			d[cur][i][j] = 0;
		}
	while (!q.empty()) {
		auto [i, j] = q.front(); q.pop_front();
		auto f = [&](int x, int y) {
			if (!valid(x, y) || g[x][y] == '#') return;
			int del = g[x][y] == '.';
			if (ckmin(d[cur][x][y], d[cur][i][j] + del)) {
				if (del) q.push_back({x, y});
				else q.push_front({x, y});
			}
		};
		f(i + 1, j); f(i - 1, j);
		f(i, j + 1); f(i, j - 1);
	}
	++cur;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	rep(i, 0, n) cin >> g[i];
	bfs('1');
	bfs('2');
	bfs('3');

	ll ans = inf;
	rep(i, 0, n) {
		rep(j, 0, m) {
			ll cur = 0;
			rep(b, 0, 3) cur += d[b][i][j];
			if (g[i][j] == '.') cur -= 2;
			ckmin(ans, cur);
		}
	}
	cout << (ans < inf ? ans : -1);
}