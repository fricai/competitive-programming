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

	string s; cin >> s;
	ll k; cin >> k;

	ll x = 0, y = 0;
	int n = sz(s);
	vector<pair<int, int>> path;
	rep(i, 0, n) {
		path.emplace_back(x, y);
		if (s[i] == 'L') --x;
		if (s[i] == 'R') ++x;
		if (s[i] == 'U') --y;
		if (s[i] == 'D') ++y;
	}
	path.emplace_back(x, y);

	sort(all(path)); path.erase(unique(all(path)), end(path));

	if (x == 0 && y == 0)
		return cout << sz(path) << '\n', 0;

	if (x == 0) {
		for (auto &[l, r] : path) {
			swap(l, r);
		}
		swap(x, y);
	}
	if (x < 0) {
		for (auto &[l, r] : path) {
			l = -l;
		}
		x = -x;
	}

	sort(all(path));
	map<ll, vector<int>> mp;
	for (auto [a, b] : path) {
		mp[a * y - b * x].push_back(a);
	}

	ll ans = 0;
	for (auto &[_, v] : mp) {
		map<int, vector<int>> st;
		for (auto a : v) {
			int r = (a % x + x) % x;
			st[r].push_back((a - r) / x);
		}
		for (auto [_, w] : st) {
			ans += k;
			for (int i = 0; i + 1 < sz(w); ++i) {
				ans += min(k, ll(w[i + 1] - w[i]));
			}
		}
	}
	cout << ans << '\n';
}
