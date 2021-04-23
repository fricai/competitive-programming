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

void solve() {
	int n, m; cin >> n >> m;

	vector<pair<int, int>> paths;
	rep(i, 0, n) {
		rep(j, 0, m) {
			int x; cin >> x;
			paths.emplace_back(x, i);
		}
	}
	sort(all(paths));
	
	vector<bool> taken(n * m, 0);
	vector<vector<int>> l(m);

	rep(i, 0, m) {
		l[i].resize(n);

		vector<bool> vis(n);
		auto add = [&](pair<int, int> p) {
			auto [d, x] = p;
			if (vis[x]) return 0;
			l[i][x] = d;
			vis[x] = 1;
			return 1;
		};
		for (int i = 0;; ++i) {
			if (taken[i]) continue;
			add(paths[i]);
			taken[i] = 1;
			break;
		}
		for (int i = n * m - 1, c = 1; c != n; --i) {
			if (taken[i]) continue;
			if (add(paths[i])) {
				taken[i] = 1;
				++c;
			}
		}
	}
	
	rep(i, 0, n) {
		rep(j, 0, m) cout << l[j][i] << ' ';
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}