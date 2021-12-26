#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	int q; cin >> q;
	vector<pair<int, int>> sp(q);
	for (auto &[x, y] : sp)
		cin >> x >> y;
	sort(all(sp));

	auto special = [&](int x, int y) -> bool { return binary_search(all(sp), pair(x, y)); };
	auto get = [&](int x, int y) { return x + y + special(x, y); };

	vector<pair<int, int>> lvl = {{1, 1}}, nxt;

	for (int dep = 0; ; ++dep) {
		nxt.clear();
		nxt.reserve(2 * sz(lvl));
		for (auto [x, y] : lvl) {
			if (x == n && y == m)
				return cout << dep << '\n', 0;
			int z = get(x, y);
			nxt.emplace_back(min(z, n), y);
			nxt.emplace_back(x, min(z, m));
		}

		sort(rall(nxt));
		lvl.clear();

		int mx = 0;
		for (auto [x, y] : nxt) {
			if (y <= mx)
				continue;
			mx = max(mx, y);
			lvl.emplace_back(x, y);
		}
	}
}
