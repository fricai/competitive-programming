
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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	int n = sz(s);
	if (n == 1) {
		if (s[0] == 'X' || s[0] == '_' || s[0] == '0')
			cout << 1 << '\n';
		else cout << "0\n";
	} else if (s[0] == '0') {
		cout << "0\n";
	} else {	
		int under = 0, cross = 0;

		rep(i, 0, n - 2) {
			under += s[i] == '_';
			cross += s[i] == 'X';
		}

		auto power = [&](int x) -> ll {
			ll p = 1;
			rep(i, 0, x) p *= 10;
			return p;
		};

		ll ans = 0;


		vector<array<int, 2>> opt = {{0, 0}, {2, 5}, {5, 0}, {7, 5}};

		if (n == 2)
			opt.erase(begin(opt));

		for (auto [i, j] : opt) {
			char cross_val = 'X';
			if (s[n - 2] == 'X')
				cross_val = i + '0';
			else if (s[n - 1] == 'X')
				cross_val = j + '0';

			string t = s;
			rep(i, 0, n)
				if (t[i] == 'X')
					t[i] = cross_val;

			int crosses = 0;
			rep(i, 0, n)
				if (t[i] == 'X')
					++crosses;

			if (t[0] == '0')
				continue;

			char a = t[n - 2];
			char b = t[n - 1];
			int count_under = (a == '_') + (b == '_');
			int cur = 0;
			if ((a == i + '0' && b == j + '0') || (count_under == 1 && (a == i + '0' || b == j + '0')) || count_under == 2) {
				cur = (n > 2 && t[0] == '_') ? power(under - 1) * 9 : power(under);
			}

			if (crosses > 0 && cross_val == 'X') {
				if (t[0] == 'X')
					cur *= 9;
				else
					cur *= 10;
			}
			ans += cur;
		}
		cout << ans << '\n';
	}
}
