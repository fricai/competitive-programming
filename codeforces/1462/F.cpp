#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 18, M = 2 * N;
int l[N], r[N];
// vector<int> cmp(M);

int solve() {
	int n; cin >> n;

	// cmp.clear();
	vector<int> L, R;
	rep(i, 0, n) {
		cin >> l[i] >> r[i];
		L.push_back(l[i]);
		R.push_back(r[i]);
		// cmp.push_back(l[i]);
		// cmp.push_back(r[i]);
	}
	sort(all(L)); sort(all(R));


	int ans = n - 1;
	rep(i, 0, n)
		ckmin<int>(ans, distance(begin(R), lb(all(R), l[i])) + distance(ub(all(L), r[i]), end(L)));
	// sort(all(cmp)); cmp.erase(unique(all(cmp)), end(cmp));


	// int m = sz(cmp);
	// rep(i, 0, m) a[i] = 0;
	// rep(i, 0, n) {
	// 	l[i] = lb(all(cmp), l[i]) - begin(cmp);
	// 	r[i] = lb(all(cmp), r[i]) - begin(cmp);
	// 	++st[l[i]];
	// 	++en[r[i]];
	// }

	// int ans = n - 1;
	// for (int x = 0, a = 0, b = n; x < m; ++x) {
	// 	if (st[x]) ckmin(ans, a + b);
	// 	a += en[x];
	// }
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}