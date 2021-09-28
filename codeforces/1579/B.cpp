#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<tuple<int, int, int>> ans;
	rep(i, 0, n) {
		auto it = min_element(begin(a) + i, end(a));
		if (it == begin(a) + i)
			continue;
		ans.emplace_back(i + 1, n, it - begin(a) - i);
		rotate(begin(a) + i, it, end(a));
	}

	assert(is_sorted(all(a)));

	cout << sz(ans) << '\n';
	for (auto [l, r, d] : ans)
		cout << l << ' ' << r << ' ' << d << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
