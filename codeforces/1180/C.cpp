#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	vector<pair<int, int>> ans; ans.reserve(n);
	deque<int> A(n);
	REP(i, 0, n) cin >> A[i];
	int m = *max_element(A.begin(), A.end());

	int cnt = 1;
	while (m != A[0]) {
		++cnt;
		int a = A[0], b = A[1];
		ans.push_back({a, b});
		if (a > b) {
			A.pop_front();
			A.pop_front();
			A.push_front(a);
			A.push_back(b);
		} else {
			A.pop_front();
			A.push_back(a);
		}
	}

	while(q--) {
		int i;
		cin >> i;
		if (i < cnt) cout << ans[i - 1].first << ' ' << ans[i - 1].second;
		else
			cout << A[0] << ' ' << A[((i - cnt) % (n - 1)) + 1];
		cout << '\n';
	}
}
