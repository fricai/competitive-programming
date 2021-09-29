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
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	if (a.front() == 1) {
		cout << n + 1 << ' ';
		rep(i, 0, n)
			cout << i + 1 << ' ';
		cout << '\n';
		return;
	}
	if (a.back() == 0) {
		rep(i, 0, n)
			cout << i + 1 << ' ';
		cout << n + 1 << '\n';
		return;
	}

	rep(i, 0, n - 1) {
		if (a[i] != 0 || a[i + 1] != 1)
			continue;
		rep(j, 0, i + 1)
			cout << j + 1 << ' ';
		cout << n + 1 << ' ';
		rep(j, i + 1, n)
			cout << j + 1 << ' ';
		cout << '\n';
		return;
	}
	cout << "-1\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}
