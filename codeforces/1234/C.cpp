#include <bits/stdc++.h>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q;
	while(q--) {
		int n; cin >> n;
		int pipes[2][n];
		REP(j, 0, 2) {
			string s; cin >> s;
			REP(i, 0, n)
				pipes[j][i] = s[i] - '0';
		}

		bool flag = true, h = 0, prev = 0;
		int i = 0;
		while (i < n)
			if (pipes[h][i] > 2) {
				if (pipes[!h][i] < 3) {
					flag = false;
				}
				if (prev) ++i;
				else h = !h;
				prev = !prev;
			} else {
				++i;
				prev = 0;
			}
		cout << ((flag && h) ? "YES" : "NO") << '\n';
	}
}