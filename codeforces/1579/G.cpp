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

constexpr int X = 2e3 + 5, inf = 1e8;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (auto &x : a)
			cin >> x;

		vector f(X, 0);
		rep(i, 0, n) {
			vector g(X, inf);
			rep(j, a[i], X) {
				uin(g[j - a[i]], a[i] + f[j]);
				uin(g[j], max(0, f[j - a[i]] - a[i]));
			}
			swap(f, g);
		}
		int ans = inf;
		rep(i, 0, X) uin(ans, i + f[i]);
		cout << ans << '\n';
	}
}
