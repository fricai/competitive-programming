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

const int N = 1 << 17, K = 18, inf = 1e9;
const ll INF = 1e18;
vector<int> g[N];
ll dp[K][1 << K];
int d[K][N];
int c[K];
bool vis[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int k; cin >> k;
	rep(i, 0, k) cin >> c[i], --c[i];
	rep(i, 0, k) {
		fill(d[i], d[i] + n, inf);
		fill(vis, vis + n, false);

		queue<int> q; d[i][c[i]] = 0; q.push(c[i]);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (vis[u]) continue;
			vis[u] = true;
			for (int v : g[u]) {
				ckmin(d[i][v], d[i][u] + 1);
				q.push(v);
			}
		}

		// rep(u, 0, n) cerr << d[i][u] << ' ';
		// cerr << '\n';
	}

	rep(i, 0, k) rep(S, 0, 1 << k) dp[i][S] = INF;
	rep(i, 0, k) dp[i][1 << i] = 0;
	rep(S, 0, 1 << k) {
		rep(i, 0, k) {
			if (~S >> i & 1) continue;
			rep(j, 0, k) {
				if (S >> j & 1) continue;
				if (d[i][c[j]] == inf) continue;
				ckmin(dp[j][S | 1 << j], dp[i][S] + d[i][c[j]]);
			}
		}
	}

	ll ans = INF;
	rep(i, 0, k) ckmin(ans, dp[i][(1 << k) - 1]);
	cout << (ans < INF ? ans + 1 : -1);
}