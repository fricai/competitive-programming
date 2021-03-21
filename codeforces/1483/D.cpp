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

const int N = 600 + 2;
const ll inf = 1e16;
ll d[N][N], l[N][N], w[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	rep(u, 0, n) rep(v, 0, n) w[u][v] = inf;
	rep(u, 0, n) w[u][u] = 0;
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		cin >> w[u][v]; w[v][u] = w[u][v];
	}

	int q; cin >> q;
	rep(i, 0, q) {
		int u, v; cin >> u >> v; --u; --v;
		cin >> l[u][v]; l[v][u] = l[u][v];
	}

	rep(u, 0, n) rep(v, 0, n) d[u][v] = w[u][v];
	rep(k, 0, n)
		rep(i, 0, n)
			rep(j, 0, n)
				ckmin(d[i][j], d[i][k] + d[k][j]);
	
	rep(i, 0, n)
		rep(j, 0, n)
			rep(k, 0, n)
				ckmax(l[k][j], l[i][j] - d[i][k]);
	
	int ans = 0;
	rep(i, 0, n)
		rep(j, 0, i) {
			bool works = 0;
			rep(k, 0, n) works |= w[i][j] + d[j][k] <= l[i][k];
			// rep(k, 0, n) works |= w[j][i] + d[i][k] <= l[j][k];
			ans += works;
		}
	cout << ans << '\n';
}