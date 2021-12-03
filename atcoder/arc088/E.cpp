#include <bits/stdc++.h>
#include <atcoder/fenwicktree>

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

constexpr int A = 26;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;

	int n = sz(s);
	vector<vector<int>> f(A);
	rep(i, 0, n) f[s[i] - 'a'].push_back(i);

	for (int c = 0, count = 0; c < A; ++c) {
		count += sz(f[c]) & 1;
		if (count > 1)
			return cout << "-1\n", 0;
	}

	vector<pair<int, int>> pairs;
	vector<int> p(n);
	for (auto &v : f) {
		for (int l = 0, r = sz(v) - 1; l < r; ++l, --r) {
			pairs.emplace_back(v[l], v[r]);
		}
		if (sz(v) & 1) p[v[sz(v) / 2]] = n / 2;
	}
	sort(all(pairs));

	int x = 0, y = n - 1;
	for (auto [l, r] : pairs) {
		p[l] = x++;
		p[r] = y--;
	}

	ll ans = 0;
	atcoder::fenwick_tree<int> t(n);
	for (int i = 0; i < n; ++i) {
		ans += t.sum(p[i], n);
		t.add(p[i], 1);
	}

	cout << ans << '\n';
}
