#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;

	vector<pair<int, int>> v(n);
	for (auto &[x, y] : v)
		cin >> x >> y;

	auto rec = [&](const auto &self, int l, int r) -> void {
		if (l > r) return;
		v.erase(find(begin(v), end(v), pair(l, r)));

		vector<int> vis(n + 2);
		for (auto [x, y] : v)
			++vis[x], --vis[y + 1];
		for (int i = 1; i <= n; ++i)
			vis[i] += vis[i - 1];

		int d = -1;
		for (int i = l; i <= r; ++i)
			if (vis[i] == 0) {
				assert(d == -1);
				d = i;
			}

		cout << l << ' ' << r << ' ' << d << '\n';
		self(self, l, d - 1);
		self(self, d + 1, r);
	};
	rec(rec, 1, n);
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
