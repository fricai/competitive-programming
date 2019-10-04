#include <algorithm>
#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	int n; cin >> n;
	int s[n];

	REP(i, 0, n) cin >> s[i];
	sort(s, s + n, greater<int>());

	int last = 1e9;
	int ans = 0;
	REP(i, 0, n) {
		if (s[i] + 1 < last) last = s[i] + 1;
		else if (s[i] < last) last = s[i];
		else if (s[i] - 1 < last && s[i] > 1) last = s[i] - 1;
		else --ans;
		++ans;
	}

	cout << ans << '\n';
}