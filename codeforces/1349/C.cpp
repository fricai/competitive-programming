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

	int n, m, t; cin >> n >> m >> t;
	vector<string> g(n);
	for (auto &row : g) cin >> row;

	const int inf = 1e9;
	vector dist(n, vector(m, inf));

	queue<pair<int, int>> q;
	rep(i, 0, n) {
		rep(j, 0, m) {
			int count = 0;
			if (i) count += g[i - 1][j] == g[i][j];
			if (j) count += g[i][j - 1] == g[i][j];
			if (i + 1 < n) count += g[i + 1][j] == g[i][j];
			if (j + 1 < m) count += g[i][j + 1] == g[i][j];
			if (count) {
				q.push({i, j});
				dist[i][j] = 0;
			}
		}
	}

	bool no_source = q.empty();
	while (!q.empty()) {
		auto [i, j] = q.front(); q.pop();
		auto add = [&](int x, int y) {
			if (!(0 <= x && x < n && 0 <= y && y < m) || dist[x][y] < inf)
				return;
			dist[x][y] = dist[i][j] + 1;
			q.push({x, y});
		};
		add(i - 1, j); add(i + 1, j);
		add(i, j - 1); add(i, j + 1);
	}
	
	while (t--) {
		int i, j; ll p; cin >> i >> j >> p; --i; --j;
		if (no_source) {
			cout << g[i][j] << '\n';
		} else {
			if (p <= dist[i][j])
				cout << g[i][j] << '\n';
			else {
				p -= dist[i][j];
				if (p & 1)
					cout << char('0' ^ '1' ^ g[i][j]) << '\n';
				else
					cout << g[i][j] << '\n';
			}
		}
	}
}