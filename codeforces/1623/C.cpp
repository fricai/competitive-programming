#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve() {
	int n; cin >> n;
	vector<ll> h(n);
	for (auto &x : h)
		cin >> x;

	ll l = 0, r = accumulate(begin(h), end(h), 0ll) + 1;

	while (r - l > 1) {
		ll x = (l + r) / 2;
		// return true if we can move stones such that each heap has >= x elements
		auto g = h;
		for (int i = n - 1; i >= 2; --i) {
			ll mv = max(0ll, min(h[i] / 3, (g[i] - x) / 3));
			g[i] -= 3 * mv;
			g[i - 1] += mv;
			g[i - 2] += 2 * mv;
		}

		if (*min_element(begin(g), end(g)) >= x) l = x;
		else r = x;
	}

	return l;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
