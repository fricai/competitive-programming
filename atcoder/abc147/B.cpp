#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s; int l = 0, r = s.size() - 1, cnt = 0;
	while (l < r) {
		if (s[l] != s[r]) ++cnt;
		++l; --r;
	}
	cout << cnt;
}