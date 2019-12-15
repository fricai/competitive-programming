#include <iostream>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

#define debug(x) cerr << #x << ' ' << (x) << '\n';

using ll = long long;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		switch(s.back()) {
			case 'o': cout << "FILIPINO\n"; break;
			case 'u': cout << "JAPANESE\n"; break;
			case 'a': cout << "KOREAN\n"; break;
		}
	}
}