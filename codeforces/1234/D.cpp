#include <bits/stdc++.h>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;

	int n = s.size();
	vector<int> v(n);
	REP(i, 0, n) v[i] = s[i] - 'a';
	set<int> freq[26];
	REP(i, 0, n) freq[v[i]].insert(i + 1);

	int q; cin >> q;
	while(q--) {
		int t; cin >> t;
		if (t == 1) {
			int pos; char c;
			cin >> pos >> c;
			REP(j, 0, 26) if (!freq[j].empty()) freq[j].erase(pos);
			freq[c - 'a'].insert(pos);
		} else {
			int l, r; int ans = 0;
			cin >> l >> r;
			REP(j, 0, 26) {
				if (freq[j].empty()) continue;
				auto itl = freq[j].lower_bound(l);
				auto itr = freq[j].upper_bound(r);
				if (distance(itl, itr) > 0) ++ans;
			}
			cout << ans << '\n';
		}
	}
}