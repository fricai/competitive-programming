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

const int N = 1 << 10;
bool g[N][N];

int col[2][N];
bool vis[2][N];

int n;
bool bip(int u, bool b, bool t) {
	if (vis[t][u]) {
		if (b != col[t][u]) return false;
		return true;
	}
	col[t][u] = b;
	vis[t][u] = true;
	if (t) { rep(v, 0, n) if (!bip(v, b ^ g[u][v], 0)) return false; }
	else { rep(v, 0, n) if (!bip(v, b ^ g[v][u], 1)) return false; }
	return true;
}

bool solve() {
	cin >> n;

	rep(i, 0, n) {
		rep(j, 0, n) {
			char c; cin >> c;
			g[i][j] = (c == '1');
		}
	}

	rep(i, 0, n) {
		rep(j, 0, n) {
			char c; cin >> c;
			g[i][j] ^= (c == '1');
		}
	}

	rep(b, 0, 2) {
		fill(vis[b], vis[b] + n, 0);
		fill(col[b], col[b] + n, 0);
	}
	return bip(0, 0, 0);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << '\n';
}