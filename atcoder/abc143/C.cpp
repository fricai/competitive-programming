#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	string s; cin >> s;
	int cnt = 0;
	int i = 0;
	while (i < n) {
		int cur = i;
		++cnt;
		while (i < n && s[cur] == s[i]) ++i;
	}
	cout << cnt;
}