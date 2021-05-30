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

	vector<tuple<int, int, int>> ops;
	auto add = [&](int i, int j) {
		ops.emplace_back(1, i + 1, j + 1);
		a[i] = a[i] + a[j];
	};

	auto sub = [&](int i, int j) {
		ops.emplace_back(2, i + 1, j + 1);
		a[j] = a[j] - a[i];
	};
	
	for (int i = 0, j = 1; j < n; i += 2, j += 2) {
		add(i, j);
		sub(i, j);
		add(i, j);
		add(i, j);
		sub(i, j);
		add(i, j);
	}

	cout << sz(ops) << '\n';
	for (auto [t, i, j] : ops)
		cout << t << ' ' << i << ' ' << j << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}