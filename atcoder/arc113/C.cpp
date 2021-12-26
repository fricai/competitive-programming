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

constexpr int A = 26;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	int n = sz(s);

	vector<pair<int, int>> v; // (r, l)

	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && s[i] == s[j]) ++j;
		if (j - i > 1) {
			v.emplace_back(i, j);
		}
	}

	if (v.empty()) {
		cout << "0\n";
		return 0;
	}

	ll ans = 0;
	for (int x = n; !v.empty(); v.pop_back()) {
		auto [l, r] = v.back();
		for (int i = r; i < x; ++i)
			ans += s[i] != s[l];
		if (x == n || s[x] != s[l]) ans += n - x;
		x = l;
	}
	cout << ans << '\n';
}
