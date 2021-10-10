#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> solve() {
	int n; char c; string s;
	cin >> n >> c >> s;

	bool all_eq = true;
	rep(i, 0, n)
		all_eq &= s[i] == c;
	if (all_eq)
		return {};

	for (int d = 1; d <= n; ++d) {
		bool ok = true;
		for (int i = d; i <= n; i += d)
			ok &= s[i - 1] == c;
		if (ok)
			return {d};
	}

	int non_div = 1;
	while (n % non_div == 0)
		++non_div;
	return {non_div, n};
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		auto x = solve();
		cout << sz(x) << '\n';
		if (!x.empty()) {
			for (auto a : x)
				cout << a << ' ';
			cout << '\n';
		}
	}
}
