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

	int a[4][4];
	rep(i, 0, 4) rep(j, 0, 4) cin >> a[i][j];

	auto get = [&](auto g, int x, int y) {
		vector vis(4, vector(4, 0));
		auto dfs = [&](const auto &self, int i, int j) -> void {
			if (i < 0 || i > 3 || j < 0 || j > 3 || g[i][j] == 0 || vis[i][j])
				return;
			vis[i][j] = true;
			self(self, i + 1, j);
			self(self, i - 1, j);
			self(self, i, j + 1);
			self(self, i, j - 1);
		};
		dfs(dfs, x, y);
		return vis;
	};

	int ans = 0;
	rep(S, 1, 1 << 16) {
		bool ok = [&]() -> bool {
			vector g(4, vector(4, 0));
			rep(i, 0, 16) {
				g[i / 4][i % 4] = S >> i & 1;
			}
			rep(i, 0, 4)
				rep(j, 0, 4)
					if (a[i][j] && !g[i][j])
						return false;

			vector<vector<int>> tot;
			rep(i, 0, 4) {
				bool to_break = false;
				rep(j, 0, 4) {
					if (g[i][j] == 0)
						continue;
					tot = get(g, i, j);
					if (tot != g)
						return false;
					break;
				}
				if (to_break) break;
			}

			auto h = g;
			rep(i, 0, 4) rep(j, 0, 4) h[i][j] = !g[i][j];

			rep(i, 0, 4) {
				rep(j, 0, 4) {
					if (tot[i][j])
						continue;
					auto v = get(h, i, j);
					bool border = false;
					rep(i, 0, 4) rep(j, 0, 4) if ((i == 0 || i == 3 || j == 0 || j == 3) && v[i][j]) border = true;
					if (!border) return false;
					rep(i, 0, 4) rep(j, 0, 4) tot[i][j] |= v[i][j];
				}
			}
			return true;
		}();
		ans += ok;
	}
	cout << ans << '\n';
}
