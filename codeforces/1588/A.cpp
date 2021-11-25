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

constexpr int X = 202;

bool solve() {
	int n; cin >> n;
	vector<int> f(X + 1), g(X + 1), h(X + 1);
	rep(i, 0, n) {
		int x; cin >> x;
		++f[x + 100];
	}
	rep(i, 0, n) {
		int x; cin >> x;
		++g[x + 100];
	}

	for (int x = 0; x < X; ++x) {
		int del = f[x] - g[x] + h[x];
		if (del < 0 || del > f[x])
			return false;
		h[x + 1] += del;
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}
}
