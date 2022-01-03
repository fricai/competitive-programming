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

constexpr int inf = 2e9 + 20;

void solve() {
	int n; cin >> n;

	map<int, int> mnl, mnr;
	map<pair<int, int>, int> mni;

	auto add = [&](auto &x, auto p, int cost) {
		auto it = x.find(p);
		if (it != end(x)) uin(it->second, cost);
		else x[p] = cost;
	};

	auto get = [&](auto &x, auto p) {
		auto it = x.find(p);
		return it == end(x) ? +inf : it->second;
	};

	int left = +inf, right = -inf;
	rep(i, 0, n) {
		int l, r, c; cin >> l >> r >> c;
		add(mnl, l, c);
		add(mnr, r, c);
		add(mni, pair(l, r), c);

		uin(left, l);
		uax(right, r);

		cout << min(get(mni, pair(left, right)), get(mnl, left) + get(mnr, right)) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
