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

const int N = 1 << 18;
const ll inf = 1e18;
ll d[N][2][2];
vector<pair<int, int>> g[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(e, 0, m) {
		int u, v, w; cin >> u >> v >> w; --u; --v;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	rep(u, 0, n) rep(i, 0, 2) rep(j, 0, 2) d[u][i][j] = inf;

	priority_queue<tuple<ll, int, int, int>> q;
	d[0][1][1] = 0; q.push({0, 0, 1, 1});
	while (!q.empty()) {
		auto [d_u, u, a, b] = q.top(); q.pop();
		if (-d_u != d[u][a][b]) continue;
		for (auto [v, w] : g[u])
			for (int x = 0; x <= a; ++x)
				for (int y = 0; y <= b; ++y)
					if (ckmin(d[v][a ^ x][b ^ y], d[u][a][b] + (1 - x + y) * w))
						q.push({-d[v][a ^ x][b ^ y], v, a ^ x, b ^ y});
	}

	rep(u, 1, n) cout << d[u][0][0] << ' ';
}