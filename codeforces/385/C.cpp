#include <iostream>
#include <vector>
#include <set>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, X = 0; cin >> n; 
	int x[n];
	REP(i, 0, n)
		cin >> x[i],
		X = max(X, x[i]);
	
	int lp[X + 1]; REP(i, 0, X + 1) lp[i] = 0;
	vector<int> pr;
	for (int i = 2; i <= X; ++i) {
    if (!lp[i]) {
			lp[i] = i;
			pr.push_back(i);
    }
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= X; ++j)
			lp[i * pr[j]] = pr[j];
	}
	
	int cnt[X + 1]; REP(i, 0, X + 1) cnt[i] = 0;
	REP(i, 0, n) {
		int a = x[i];
		set<int> s;
		while (a > 1) {
			s.insert(lp[a]);
			a /= lp[a];
		}
		for (int p : s) ++cnt[p];
	}

	REP(i, 1, X) cnt[i + 1] += cnt[i];
	int m; cin >> m;
	while (m--) {
		int l, r; cin >> l >> r; --l;
		l = min(l , X); r = min(r, X);
		cout << cnt[r] - cnt[l] << '\n';
	}
}