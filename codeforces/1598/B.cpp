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

bool solve() {
	int n; cin >> n;
	vector<array<int, 5>> a(n);
	for (auto &x : a)
		for (auto &y : x)
			cin >> y;

	rep(one, 0, 5) {
		rep(two, 0, one) {
			vector<int> c(4);
			for (auto x : a)
				++c[x[one] | x[two] << 1];
			if (c[0] == 0 && (c[1] <= n / 2 && c[2] <= n / 2))
				return true;
		}
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}
