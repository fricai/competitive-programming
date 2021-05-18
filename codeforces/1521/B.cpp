#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<tuple<int, int, int, int>> op;
	auto do_op = [&](int i, int j, int x, int y) {
		if (i == j) {
			assert(x == y);
			assert(a[i] == x);
			return;
		}

		assert(min(a[i], a[j]) == min(x, y));

		a[i] = x;
		a[j] = y;
		op.emplace_back(i + 1, j + 1, x, y);
		assert(sz(op) <= n);
	};

	int smallest = min_element(all(a)) - begin(a);
	int min_val = a[smallest];
	
	do_op(0, smallest, min_val, a[0]);
	
	for (int i = 1; i < n; ++i)
		do_op(0, i, a[0], a[0] + i);

	rep(i, 1, n) assert(gcd(a[i], a[i - 1]) == 1);

	cout << sz(op) << '\n';
	for (auto [i, j, x, y] : op)
		cout << i << ' ' << j << ' ' << x << ' ' << y << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}