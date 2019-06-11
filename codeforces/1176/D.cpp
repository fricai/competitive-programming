#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i != (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int bmax = 2750131, nmax = 2e5;
	vector<int> pr(nmax), lp(bmax + 1, 0);

	int cur = 0;
	REP(i, 2, bmax + 1) {
		if (lp[i] == 0)
			lp[i] = pr[++cur] = i;
		for (int j = 0; j <= cur && pr[j] <= lp[i] && i * pr[j] <= bmax; ++j)
			lp[i * pr[j]] = pr[j];
	}

	int n; cin >> n;
	vector<int> a; a.reserve(n);
	multiset<int> b;

	REP(i, 0, 2 * n) {
		int x; cin >> x;
		b.insert(x);
	}

	REP(it, b.rbegin(), b.rend()) {
		int i = *it;
		if (lp[i] == i) {
			int pos = lower_bound(pr.begin(), pr.end(), i) - pr.begin();
			a.push_back(pos); b.erase(b.find(pos));
		} else {
			a.push_back(i); b.erase(b.find(i/lp[i]));
		}
	}

	REP(i, 0, n) cout << a[i] << ' ';
}
