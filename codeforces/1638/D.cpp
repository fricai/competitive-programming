#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector a(n, vector(m, 0));
	for (auto &v : a)
		for (auto &x : v)
			cin >> x;

	vector vis(n - 1, vector(m - 1, false));
	vector<tuple<int, int, int>> ops;

	const auto get_set = [&](int i, int j) -> set<int> {
		// get the set of colors of the 2x2 square whose top-left is (i, j)
		if (i < 0 || i + 1 >= n || j < 0 || j + 1 >= m) return {};
		return {a[i][j], a[i + 1][j], a[i][j + 1], a[i + 1][j + 1]};		
	};

	vector<pair<int, int>> q;
	const auto enqueue = [&](int i, int j) -> void {
		if (i < 0 || i + 1 >= n || j < 0 || j + 1 >= m) return;
		if (vis[i][j]) return;
		const auto cols = get_set(i, j);
		if (sz(cols) == 1 || (sz(cols) == 2 && *begin(cols) == 0)) {
			vis[i][j] = true;
			q.emplace_back(i, j);
		}
	};

	rep(i, 0, n - 1) rep(j, 0, m - 1) enqueue(i, j);


	const auto do_op = [&](int i, int j, int col) {
		ops.emplace_back(i, j, col);
		a[i][j] = a[i + 1][j] = a[i][j + 1] = a[i + 1][j + 1] = 0;
	};

	while (!q.empty()) {
		const auto [i, j] = q.back();

		q.pop_back();
		const auto cols = get_set(i, j);
		if ((sz(cols) == 1 && *begin(cols) != 0) || (sz(cols) == 2 && *begin(cols) == 0)) {
			do_op(i, j, *cols.rbegin());
			for (auto di : {-1, 0, +1})
				for (auto dj : {-1, 0, +1})
					enqueue(i + di, j + dj);
		}
	}

	for (auto &v : a)
		if (any_of(all(v), [](int x) { return x != 0; }))
			return cout << "-1\n", 0;

	reverse(all(ops));
	cout << sz(ops) << '\n';
	for (auto [i, j, c] : ops)
		cout << i + 1 << ' ' << j + 1 << ' ' << c << '\n';
}
