#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

int main() {
	int n, m, ans = 0; cin >> n >> m;
	bool grid[n][m], dp[n][m][n][m]; // (x)
	REP(i, 0, n) {
		string r; cin >> r;
		REP(j, 0, m) grid[i][j] = 1 - (r[j] - '0');
	}
	REP(x1, 0, n)
		REP(y1, 0, m)
			REP(x2, x1, n)
				REP(y2, y1, m) {
					auto &d = dp[x1][y1];
					if (grid[x2][y2]) {
						if (x1 != x2 && y1 != y2)
							d[x2][y2] = d[x2 - 1][y2] && d[x2][y2 - 1];
						else if (x1 == x2 && y1 != y2)
							d[x2][y2] = d[x2][y2 - 1];
						else if (x1 != x2 && y1 == y2)
							d[x2][y2] = d[x2 - 1][y2];
						else d[x2][y2] = grid[x2][y2];
						if (d[x2][y2])
							ans = max(ans, 2 * (x2 + y2 - x1 - y1 + 2));
					} else d[x2][y2] = 0;
				}

	cout << ans;
}
