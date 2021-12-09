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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector g(n, vector(m, 0));
	for (auto &v : g)
		for (auto &x : v)
			cin >> x, --x;

	ll x = g[0][0] / 7, y = g[0][0] % 7;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (y + j >= 7 || g[i][j] != (x + i) * 7 + (y + j)) {
				return cout << "No\n", 0;
			}
		}
	}
	cout << "Yes\n";
}
