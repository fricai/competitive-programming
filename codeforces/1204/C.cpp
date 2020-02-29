#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

const int N = 1 << 7, M = 1 << 20, inf = 1e9;
int n;
int d[N][N], p[M];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	rep(i, 0, n) {
		rep(j, 0, n) {
			char c; cin >> c;
			if (c == '1') d[i][j] = 1;
			else d[i][j] = inf;
		}	
		d[i][i] = 0;
	}
	rep(k, 0, n)
		rep(i, 0, n)
			rep(j, 0, n)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int m; cin >> m;
	rep(i, 0, m) cin >> p[i], --p[i];

	vector<int> a(1, p[0]);

	int dist = 0;
	rep(i, 1, m) {
		if (d[a.back()][p[i]] < ++dist) {
			dist = 1;
			a.push_back(p[i - 1]);
		}
	}
	a.push_back(p[m - 1]);
	cout << a.size() << '\n';
	for (int v : a) cout << v + 1 << ' ';
}