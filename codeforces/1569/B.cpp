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

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	vector<int> win;
	rep(i, 0, n)
		if (s[i] == '2')
			win.push_back(i);
	if (sz(win) == 1 || sz(win) == 2)
		return void(cout << "NO\n");

	vector g(n, string(n, '='));
	rep(i, 0, n) g[i][i] = 'X';
	rep(i, 0, sz(win)) {
		int x = win[i], y = win[i + 1 == sz(win) ? 0 : i + 1];
		g[x][y] = '+';
		g[y][x] = '-';
	}

	cout << "YES\n";
	for (auto row : g)
		cout << row << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
