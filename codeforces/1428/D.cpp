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

const int N = 1 << 17;
int a[N];

vector<pair<int, int>> solve() {
	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];

	vector<pair<int, int>> ans;
	set<pair<int, int>> two, three;

	int cur = n - 1;
	per(i, 0, n) {
		if (a[i] == 1) {
			ans.emplace_back(cur, i);
			two.insert({cur, i});
			three.insert({cur, i});
			--cur;
		}
		if (a[i] == 2) {
			if (two.empty()) return {{-1, -1}};
			auto [r, c] = *two.begin();
			two.erase(two.begin());
			three.erase({r, c});
			three.insert({r, i});
			ans.emplace_back(r, i);
		}
		if (a[i] == 3) {
			if (three.empty()) return {{-1, -1}};
			auto [r, c] = *three.begin();
			three.erase(three.begin());
			two.erase({r, c});
			three.insert({cur, i});
			ans.emplace_back(cur, i);
			ans.emplace_back(cur, c);
			--cur;
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto v = solve();
	if (!v.empty() && v[0].first < 0) return cout << -1, 0;

	cout << sz(v) << '\n';
	for (auto [x, y] : v) cout << x + 1 << ' ' << y + 1 << '\n';
}