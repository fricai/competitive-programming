#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> T[n][2];
	REP(i, 0, n) {
		int a; cin >> a;
		while (a--) {
			int x, y; cin >> x >> y; --x;
			T[i][y].emplace_back(x);
		}
	}

	auto solve = [&](int s) {
		bool b[n];
		REP(i, 0, n) b[i] = (s >> i) & 1;
		REP(i, 0, n)
			if (b[i])
				REP(j, 0, 2)
					for (int x : T[i][j])
						if (b[x] != j) return false;
		return true;
	};

	int cur = 0;
	REP(s, 1, 1 << n)
		if (solve(s)) {
			cur = max(cur, __builtin_popcount(s));
		}
	cout << cur;
}