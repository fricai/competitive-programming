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
	vector<string> g(n);
	for (auto &s : g)
		cin >> s;

	vector<int> p(m);
	rep(i, 1, n) {
		rep(j, 1, m) {
			if (g[i - 1][j] != 'X' || g[i][j - 1] != 'X')
				continue;
			++p[j];
		}
	}
	rep(i, 1, m) p[i] += p[i - 1];

	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		cout << (p[l - 1] < p[r - 1] ? "NO" : "YES") << '\n';
	}
}
