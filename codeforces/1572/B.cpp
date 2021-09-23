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

	int cur = 0;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
		cur ^= x;
	}
	
	if (cur != 0)
		return void(cout << "NO\n");

	vector<int> ops;
	
	auto do_op = [&](int i) {
		assert(0 <= i && i < n - 2);
		int x = a[i] ^ a[i + 1] ^ a[i + 2];
		a[i] = a[i + 1] = a[i + 2] = x;
		ops.push_back(i);
	};

	auto solve = [&](int l, int r) {
		assert((r - l) % 2);
		for (int i = l; i < r - 2; i += 2)
			do_op(i);
		for (int i = r - 5; i >= l; i -= 2)
			do_op(i);
	};
	
	if (n & 1) solve(0, n);
	else {
		int j = 1; cur = a[0];
		for ( ; j + 1 < n; j += 2) {
			if (cur == 0)
				break;
			cur ^= a[j] ^ a[j + 1];
		}
		if (cur != 0)
			return void(cout << "NO\n");

		solve(0, j);
		solve(j, n);
	}

	for (auto x : a)
		assert(x == 0);

	cout << "YES\n";
	cout << sz(ops) << '\n';
	for (auto x : ops)
		cout << x + 1 << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
