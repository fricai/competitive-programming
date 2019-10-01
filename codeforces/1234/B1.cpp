#include <bits/stdc++.h>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	int id[n];
	map<int, bool> on;
	deque<int> screen;
	REP(i, 0, n) {
		int idi; cin >> idi;
		if (!on[idi]) {
			if (screen.size() == k) {
				on[screen.back()] = false;
				screen.pop_back();
			}
			on[idi] = true;
			screen.push_front(idi);
		}
	}
	cout << screen.size() << '\n';
	for (int s : screen) cout << s << ' ';
}