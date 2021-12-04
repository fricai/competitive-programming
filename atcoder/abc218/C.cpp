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

	int n; cin >> n;
	vector<string> s(n), t(n);
	for (auto &row : s) cin >> row;
	for (auto &row : t) cin >> row;

	vector<pair<int, int>> check;
	rep(i, 0, n) rep(j, 0, n) if (s[i][j] == '#') check.emplace_back(i, j);
	int count = sz(check);
	rep(i, 0, n) rep(j, 0, n) count -= t[i][j] == '#';
	if (count != 0)
		return cout << "No\n", 0;

	rep(rot, 0, 4) {
		rep(x, -n + 1, n) {
			rep(y, -n + 1, n) {
				bool fine = true;
				for (auto [i, j] : check) {
					if (!(0 <= x + i && x + i < n && 0 <= y + j && y + j < n && t[x + i][y + j] == '#')) {
						fine = false;
						break;
					}
				}
				if (fine)
					return cout << "Yes\n", 0;
			}
		}

		for (auto &[l, r] : check) {
			tie(l, r) = pair(r, n - l - 1);
		}
	}
	cout << "No\n";
}
