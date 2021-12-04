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

	bool eq = true;
	rep(i, 1, 4) if (s[i] != s[0]) eq = false;

	bool oth = true;
	rep(i, 1, 4) {
		int x = s[i - 1] - '0';
		if ((x + 1) % 10 != s[i] - '0')
			oth = false;
	}

	cout << (eq || oth ? "Weak" : "Strong") << '\n';
}
