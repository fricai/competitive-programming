#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a);)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template <class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int mod = 119 << 23 | 1, N = 2e5 + 10;
int row[N], col[N];

int solve() {
	int n, m, k, q;
	cin >> n >> m >> k >> q;

	vector<pair<int, int>> ops(q);
	for (auto& [x, y] : ops) cin >> x >> y, --x, --y;
	reverse(all(ops));

	int rowc = 0, colc = 0;
	ll ans = 1;

	for (auto [x, y] : ops) {
		if (row[x] == 0 || col[y] == 0) ans = ans * k % mod;
		rowc -= row[x];
		row[x] = 1;
		rowc += row[x];

		colc -= col[y];
		col[y] = 1;
		colc += col[y];

		if (rowc == n || colc == m) break;
	}
	for (auto [x, y] : ops) row[x] = col[y] = 0;
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) cout << solve() << '\n';
}
