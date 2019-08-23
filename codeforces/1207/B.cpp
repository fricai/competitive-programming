#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	int n, m; cin >> n >> m;
	int a[n][m], b[n][m];
	REP(i, 0, n) {
		REP(j, 0, m) {
			cin >> a[i][j];
			b[i][j] = 0;
		}
	}
	vector<pair<int, int>> op; op.reserve(n * n); 
	REP(i, 0, n - 1) {
		REP(j, 0, m - 1) {
			if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {
				b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
				op.push_back(make_pair(i + 1, j + 1));
			}
		}
	}
	bool flag = 1;
	REP(i, 0, n)
		REP(j, 0, m)
			if (a[i][j] != b[i][j])
				flag = 0;
	if (flag) {
		cout << op.size() << '\n';
		for (auto o : op) cout << o.first << ' ' << o.second << '\n';
	} else cout << -1;
}