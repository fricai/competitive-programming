#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// Input
	int n, t;
	cin >> n >> t;

	vector<long long> A(n); long long mx = 0;
	REP(i, 0, n) cin >> A[i], mx = max(mx, A[i]);

	struct query { int l, r, idx; };
	vector<query> Q(t);
	REP(i, 0, t) cin >> Q[i].l >> Q[i].r, Q[i].idx = i, --Q[i].l, --Q[i].r;

	// Sort Queries
	int block_size = sqrt(n + .0);
	sort(Q.begin(), Q.end(), [&](query &a, query &b){
		int x = a.l/block_size, y = b.l/block_size;
		if (x != y) return x < y;
		return ((x & 1) ? a.r < b.r : a.r > b.r);
	});

	// Mo
	vector<long long> ans(t), K(mx + 1, 0);
	int cur_l = 0, cur_r = -1;
	long long track = 0;
	for (auto &q : Q) {
		auto change = [&](int s, bool b) {
			auto &k = K[A[s]];
			track -= 1LL * k * k * A[s];
			k += 1 - 2 * b;
			track += 1LL * k * k * A[s];
		};
		while (cur_l > q.l) change(--cur_l, 0);
		while (cur_r < q.r) change(++cur_r, 0);
		while (cur_l < q.l) change(cur_l++, 1);
		while (cur_r > q.r) change(cur_r--, 1);
		ans[q.idx] = track;
	}

	REP(i, 0, t) cout << ans[i] << '\n';
}
