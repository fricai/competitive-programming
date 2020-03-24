#include <iostream>
#include <vector>

using namespace std;
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)

template<class T> bool ckmin(T &a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T& b) { return a < b ? a = b, 1 : 0; }

constexpr int inf = 1e9;

int solve() {
	int n; cin >> n;
	vector<int> nxt(n), c(n), vis(n), a(n);
	trav(x, nxt) cin >> x, --x;
	trav(x, c) cin >> x;
	int ans = inf;
	rep(i, 0, n) {
		int u;
		for (u = i; !vis[u]; u = nxt[u]) vis[u] = i + 1;
		if (vis[u] != i + 1) continue;
		int m = 1; a[0] = c[u];
		for (int init = u; u = nxt[u], u != init; ++m) a[m] = c[u];
		for (int d = 1; d <= m && d < ans; ++d) {
			if (m % d != 0) continue;
			vector<bool> check(d, true);
			rep(x, 0, d)
				for (int z = x; z < m; z += d)
					if (a[x] != a[z])
						check[x] = false;
			bool changed = false;
			rep(x, 0, d)
				if (check[x])
					ans = d, changed = true;
			if (changed) break;
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}