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

const int N = 1 << 11;
const ll inf = 1e18;
ll d[N][N];
vector<pair<int, int>> g[N];
int n;

void dijkstra(int s, ll d[]) {
	fill_n(d, n, inf);
    d[s] = 0;

    using P = pair<ll, int>;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, s});
    while (!q.empty()) {
		auto [d_v, v] = q.top(); q.pop();
        if (d_v != d[v]) continue;
        for (auto [to, len] : g[v])
            if (ckmin(d[to], d[v] + len))
				q.push({d[to], to});
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m; cin >> n >> m;
	rep(e, 0, m) {
		int u, v, w; cin >> u >> v >> w; --u; --v;
		g[u].emplace_back(v, w);
	}
	rep(u, 0, n) dijkstra(u, d[u]);
	rep(u, 0, n) {
		ll ans = inf;
		for (auto [v, w] : g[u])
			ckmin(ans, w + d[v][u]);
		cout << (ans < inf ? ans : -1) << '\n';
	}
}