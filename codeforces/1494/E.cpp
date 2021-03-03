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

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	map<pair<int, int>, char> edges;
	int loops = 0, same_loops = 0;

	while (m--) {
		char t; cin >> t;
		if (t == '+') {
			int u, v; char c; cin >> u >> v >> c;
			edges[{u, v}] = c;
			auto x = edges[{v, u}];
			if (x == c) ++same_loops;
			if (x) ++loops;
		}
		if (t == '-') {
			int u, v; cin >> u >> v;
			auto x = edges[{v, u}];
			auto &y = edges[{u, v}];
			if (x == y) --same_loops;
			if (x) --loops;
			y = 0;
		}
		
		if (t == '?') {
			int k; cin >> k;
			cout << ((same_loops || (loops && (k & 1))) ? "YES" : "NO") << '\n';
		}
	}
}