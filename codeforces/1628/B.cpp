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

bool solve() {
	int n; cin >> n;
	vector<string> v(n);
	for (auto &s : v) cin >> s;
	set strings(begin(v), end(v));
	for (auto s : v) {
		const string t = {rall(s)};
		if (strings.count(t)) return true;
	}

	strings.clear();
	per(i, 0, n) {
		const auto &s = v[i];
		if (sz(s) == 2) {
			strings.insert(s);
		} else if (sz(s) == 3) {
			auto t = s.substr(0, 2);
			reverse(all(t));
			if (strings.count(t)) return true;
		} else assert(false);
	}

	strings.clear();
	rep(i, 0, n) {
		const auto &s = v[i];
		if (sz(s) == 2) {
			strings.insert(s);
		} else if (sz(s) == 3) {
			auto t = s.substr(1, 2);
			reverse(all(t));
			if (strings.count(t)) return true;
		} else assert(false);
	}

	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}
