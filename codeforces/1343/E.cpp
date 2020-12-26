#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 1 << 18, M = 1 << 18;
int d1[N], d2[N], d3[N];
ll p[M];
vector<int> g[N];

int n;
void bfs(int s, int d[]) {
	queue<int> q;
	q.push(s);
	fill(d, d + n, N);
	d[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) {
			if (d[v] != N) continue;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
}

ll solve() {
	int m, a, b, c; cin >> n >> m >> a >> b >> c;
	rep(e, 0, m) cin >> p[e];

	rep(u, 0, n) g[u].clear();
	rep(e, 0, m) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v); g[v].push_back(u);
	}

	bfs(--a, d1); bfs(--b, d2); bfs(--c, d3);
	
	// rep(u, 0, n) cerr << d1[u] << ' ' << d2[u] << ' ' << d3[u] << '\n';

	sort(p, p + m);
	rep(e, 1, m) p[e] += p[e - 1];
	// rep(e, 0, m) cerr << p[e] << ' ';

	ll ans = 1e18;
	rep(u, 0, n) {
		int d = d1[u] + d2[u] + d3[u];
		if (d <= m) ckmin(ans, p[d - 1] + p[d2[u] - 1]);
	}

	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}