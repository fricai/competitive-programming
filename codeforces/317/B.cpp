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

const int B = 1 << 8, C = 1 << 7;
int g[B][B];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, t; cin >> n >> t;
	g[C][C] = n;
	for (bool changed = true; changed; ) {
		changed = false;
		rep(i, 0, B) {
			rep(j, 0, B) {
				if (g[i][j] < 4) continue;
				changed = true;
				int del = g[i][j] / 4;
				g[i][j + 1] += del;
				g[i + 1][j] += del;
				g[i][j - 1] += del;
				g[i - 1][j] += del;
				g[i][j] -= 4 * del;
			}
		}
	}
	while (t--) {
		ll x, y; cin >> x >> y; x += C, y += C;
		if (x < 0 || x >= B || y < 0 || y >= B) cout << "0\n";
		else cout << g[x][y] << '\n';
	}
}