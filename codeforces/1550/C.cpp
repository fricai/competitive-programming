#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

int solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	auto d = [&](int i, int j) {
		return abs(a[i] - a[j]) + abs(i - j);
	};
	auto ok = [&](int i, int j, int k) {
		return d(i, k) != d(i, j) + d(j, k);
	};

	int ans = 0;
	for (int l = 0; l < n; ++l) {
		for (int k = l; k < n; ++k) {
			bool stop = 0;
			for (int i = l; i < k; ++i)
				for (int j = i + 1; j < k; ++j)
					if (!ok(i, j, k) || !ok(j, k, i) || !ok(k, i, j))
						stop = 1;
			if (stop) break;
			++ans;
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}