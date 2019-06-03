#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define REP(i, a, b) for (auto i = (a); i < (b); ++i)
using namespace std;


int n, t, block_size;

struct query { int l, r, idx; };

vector<long long> A;
vector<query> Q;
vector<long long> ans;

vector<long long> K;
long long track = 0;
void add(int s) {
	auto &k = K[A[s]];
	track -= k * k * A[s];
	++k;
	track += k * k * A[s];
}

void remove(int s) {
	auto &k = K[A[s]];
	track -= k * k * A[s];
	--k;
	track += k * k * A[s];
}

void mo() {
	ans.resize(t);
	sort(Q.begin(), Q.end(), [&](query &a, query &b){
		int x = a.l/block_size, y = b.l/block_size;
		if (x != y) return x < y;
		return ((x & 1) ? a.r < b.r : a.r > b.r);
	});

	int cur_l = 0;
	int cur_r = -1;
	for (auto &q : Q) {
		while (cur_l > q.l) add(--cur_l);
		while (cur_r < q.r) add(++cur_r);
		while (cur_l < q.l) remove(cur_l++);
		while (cur_r > q.r) remove(cur_r--);
		ans[q.idx] = track;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> t;
	A.resize(n); Q.resize(t);

	long long mx = 0;
	REP(i, 0, n) cin >> A[i], mx = max(mx, A[i]);
	K.resize(mx + 1, 0); block_size = sqrt(n + .0);

	REP(i, 0, t) cin >> Q[i].l >> Q[i].r, Q[i].idx = i, --Q[i].l, --Q[i].r;

	mo();
	REP(i, 0, t) cout << ans[i] << '\n';
}
