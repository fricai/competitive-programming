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

string solve() {
	string s; cin >> s;
	string t; cin >> t;
	sort(all(s));
	if (t == "abc") {
		int a = 0;
		while (a < sz(s) && s[a] == 'a') ++a;
		int b = a;
		while (b < sz(s) && s[b] == 'b') ++b;
		int c = b;
		while (c < sz(s) && s[c] == 'c') ++c;
		if (a > 0) {
			for (int i = a; i < a + (c - b); ++i)
				s[i] = 'c';
			for (int i = a + (c - b); i < c; ++i)
				s[i] = 'b';
		}
	}
	return s;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
