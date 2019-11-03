#include <iostream>
#include <algorithm>

#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	int n = s.size(); ++n;
	int ans = 0, a[n];
	REP(i, 0, n) a[i] = 0;

	REP(i, 0, n - 1) if (s[i] == '<') a[i + 1] = a[i] + 1;
	for (int i = n - 2; i >= 0; --i) {
		if (s[i] == '>')
			a[i] = max(a[i], a[i + 1] + 1);
	}

	REP(i, 0, n) ans += a[i];
	cout << ans;
}