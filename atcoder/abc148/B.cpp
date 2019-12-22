#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

using ll = long long;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; string s[2]; cin >> n >> s[0] >> s[1];
	REP(i, 0, 2 * n) cout << s[i & 1][i >> 1];
}