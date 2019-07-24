#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

string gen(int n, int b) {
	string s(n, '0');
	REP(i, 0, n) {
		switch((i + b) % 3) {
			case 0:
				s[i] = 'R';
				break;
			case 1:
				s[i] = 'G';
				break;
			case 2:
			 s[i] = 'B';
			 break;
		}
	}
	return s;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q; cin >> q;
	while (q--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		
		int ans = n;
		REP(b, 0, 3) {
			string t = gen(n, b);
			int diff = 0;
			REP(i, 0, k)
				if (s[i] != t[i])
					 ++diff;
			ans = min(ans, diff);
			REP(i, k, n) {
				if (s[i - k] != t[i - k]) --diff;
				if (s[i] != t[i]) ++diff;
				ans = min(ans, diff);
			}
		}
		cout << ans << '\n';
	}
}