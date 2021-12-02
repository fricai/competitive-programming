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

#pragma GCC optimize ("trapv") 

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<ll> a(n);
	for (auto &x : a)
		cin >> x;

	vector<pair<int, int>> op;
	auto do_op = [&](int x, int y) {
		op.emplace_back(x, y);
		a[y] += a[x];
	};

	int mx = max_element(all(a)) - begin(a);
	int mn = min_element(all(a)) - begin(a);
	if (a[mx] + a[mn] > 0) {
		for (int i = 0; i < n; ++i) {
			if (i != mx)
				do_op(mx, i);
		}
		for (int i = 1; i < n; ++i) {
			do_op(i - 1, i);
		}
	} else {
		for (int i = 0; i < n; ++i) {
			if (i != mn)
				do_op(mn, i);
		}
		for (int i = n - 1; i > 0; --i) {
			do_op(i, i - 1);
		}
	}

	assert(is_sorted(all(a)));
	cout << sz(op) << '\n';
	for (auto [x, y] : op)
		cout << x + 1 << ' ' << y + 1 << '\n';
}
