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

	int n; ll x, d; cin >> n >> x >> d;
	if (d == 0)
		return cout << (x == 0 ? 1 : n + 1), 0;
	if (d < 0) d = -d, x = -x;

	map<int, vector<pair<ll, ll>>> mp;
	for (ll k = 0; k <= n; ++k) {
		ll r = (k * x % d + d) % d;
		ll s = (k * x - r) / d;
		mp[r].emplace_back(s + k * (k - 1) / 2, s + k * n - k * (k + 1) / 2);
	}

	ll ans = 0;
	for (auto &[_, v] : mp) {
		sort(all(v));

		stack<pair<ll, ll>> s;
		for (auto [l, r] : v) {
			if (s.empty()) s.push({l, r});
			else {
				auto [x, y] = s.top();
				if (y < l)
					s.push({l, r});
				else {
					s.pop();
					s.push({x, max(y, r)});
				}
			}
		}

		while (!s.empty()) {
			auto [l, r] = s.top(); s.pop();
			ans += r - l + 1;
		}
	}

	cout << ans << '\n';
}
