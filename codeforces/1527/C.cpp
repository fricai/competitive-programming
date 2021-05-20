#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	auto cmp = a;
	sort(all(cmp)); cmp.erase(unique(all(cmp)), end(cmp));

	vector<vector<int>> f(sz(cmp));
	rep(i, 0, n)
		f[lower_bound(all(cmp), a[i]) - begin(cmp)].push_back(i);

	ll res = 0;
	for (auto &v : f) {
		ll sum = 0;
		for (auto x : v) sum += n - x;
		for (auto x : v) {
			sum -= n - x;
			res += sum * (x + 1);
		}
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}