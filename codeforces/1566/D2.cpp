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

int solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n * m);
	for (auto &x : a)
		cin >> x;

	vector<pair<int, int>> p(n * m);
	rep(i, 0, n * m) p[i] = {a[i], i};
	sort(all(p));
	vector<pair<int, int>> seat(n * m);

	for (int i = 0, j = 0, last_row = 0, unfilled = m; i < n * m; i = j) {

		while (j < n * m && p[i].first == p[j].first)
			++j;

		while (j - i >= unfilled) {
			int z = m;
			rep(k, i, i + unfilled) {
				seat[p[k].second] = {last_row, --z};
			}
			i += unfilled;
			unfilled = m;
			++last_row;
		}
		int s = m - unfilled;
		per(k, i, j) {
			seat[p[k].second] = {last_row, s++};
			--unfilled;
		}
		assert(unfilled != 0);
	}

	vector<vector<int>> seating(n, vector(m, 0));
	rep(i, 0, n * m) {
		auto [row, col] = seat[i];
		seating[row][col] = i + 1;
	}

	/*
	cerr << '\n';
	rep(i, 0, n) {
		rep(j, 0, m)
			cerr << seating[i][j] << ' ';
		cerr << '\n';
	}
	cerr << '\n';
	*/

	int ans = 0;
	vector taken(n, vector(m, false));
	rep(i, 0, n * m) {
		auto [row, col] = seat[i];
		rep(j, 0, col)
			ans += taken[row][j];
		taken[row][col] = true;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
