#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w; cin >> h >> w;
	bool A[h][w], grid[h][w];
	REP(i, 0, h) {
		REP(j, 0, w) {
			char x; cin >> x;
			A[i][j] = (x == '*');
		}
	}

	REP(i, 0, h)
		REP(j, 0, w)
			grid[i][j] = 0;

	bool ans = 0;
	REP(i, 1, h - 1) {
		REP(j, 1, w - 1) {
			if (A[i][j] && A[i + 1][j] && A[i - 1][j] && A[i][j + 1] && A[i][j - 1]) {
				grid[i][j] = 1;
				int x = i + 1;
				while (A[x][j] && x < h) {
					grid[x][j] = 1;
					++x;
				}
				x = i - 1;
				while (A[x][j] && x >= 0) {
					grid[x][j] = 1;
					--x;
				}

				x = j + 1;
				while (A[i][x] && x < w) {
					grid[i][x] = 1;
					++x;
				}

				x = j - 1;
				while (A[i][x] && x >= 0) {
					grid[i][x] = 1;
					--x;
				}
				ans = 1;
				break;
			}
		}
		if (ans) break;
	}

	if (ans) {
		REP(i, 0, h) {
			REP(j, 0, w) {
				if (A[i][j] && !grid[i][j]) {
					ans = 0;
					break;
				}
			}
			if (!ans) break;
		}
	}

	cout << (ans ? "YES" : "NO");
}
