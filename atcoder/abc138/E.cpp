#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	string ss; cin >> ss;
	string ts; cin >> ts;
	int n = ss.size(), m = ts.size();

	int s[n], t[m];
	REP(i, 0, m) t[i] = ts[i] - 'a';
	REP(i, 0, n) s[i] = ss[i] - 'a';
	vector<int> freq[27];
	REP(i, 0, n) freq[s[i]].push_back(i);
	
	REP(i, 0, m) 
		if (freq[t[i]].empty()) {
			cout << -1;
			return 0;
		}

	int prev = -1;
	long long ans = 0;
	REP(i, 0, m) {
		auto it = upper_bound(freq[t[i]].begin(), freq[t[i]].end(), prev);
		if (it != freq[t[i]].end())
			prev = *it;
		else {
			++ans;
			prev = freq[t[i]][0];
		}
	}
	ans *= n;
	ans += prev + 1;
	cout << ans;
}