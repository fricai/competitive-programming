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

const int N = 1 << 17, M = 1 << 18;
int a[M], b[M], c[M];
vector<int> g[N];
vector<pair<int, int>> adj[2 * M];
vector<pair<int, int>> vec;
int d[2 * M];
int tot;

void add_edge(int u, int v, int w) { adj[u].emplace_back(v, w); }

int get(int u, int c) {
	// assert(binary_search(all(vec), pair(u, c)));
	return lb(all(vec), pair(u, c)) - begin(vec);
}

void dij(int s) {
	fill(d, d + tot, 25 * M);
	d[s] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    while (!q.empty()) {
		auto [d_v, v] = q.top(); q.pop();
        if (-d_v != d[v]) continue;
        for (auto [to, len] : adj[v])
			if (ckmin(d[to], d[v] + len)) q.push({-d[to], to});
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(e, 0, m) {
		cin >> a[e] >> b[e] >> c[e];
		g[a[e]].push_back(e);
		g[b[e]].push_back(e);
		vec.emplace_back(a[e], c[e]);
		vec.emplace_back(b[e], c[e]);
	}

	for (int u = 1; u <= n; ++u) {
		sort(all(g[u]), [&](int u, int v) {
			return c[u] < c[v];
		});
		vec.emplace_back(u, 0);
	}

	sort(all(vec)); vec.erase(unique(all(vec)), end(vec));

	tot = sz(vec);

	for (int u = 1; u <= n; ++u) {
		for (auto e : g[u]) {
			int v = a[e] ^ b[e] ^ u;
			assert(vec[get(v, c[e])] == pair(v, c[e]));
		}
	}

	for (int i = 0, j = 0; i < tot; i = j) {
		while (j < tot && vec[i].first == vec[j].first) ++j;
		assert(vec[i].second == 0);

		rep(r, i + 1, j) {
			add_edge(i, r, 0);
			add_edge(r, i, 1);
		}

		int u = vec[i].first;
		int t = 0;
		rep(r, i + 1, j) {
			int col = vec[r].second;
			
			while (t < sz(g[u]) && c[g[u][t]] == col) {
				int v = a[g[u][t]] ^ b[g[u][t]] ^ u;
				// assert(col)
				int nxt = get(v, col);
				// assert(vec[nxt] == pair(v, col));
				add_edge(r, nxt, 0);
				++t;
			}
		}
		assert(t == sz(g[u]));
	}

	dij(0);

	// for (int u = 0; u <= tot; ++u) {
	// for (auto [x, y] : adj[u]) {
	// 	cerr << '(' << x << ' ' << y << ") ";
	// }
	// 	cerr << '\n';
	// }

	int ans = d[get(n, 0)];
	cout << (ans < M ? ans : -1);
}