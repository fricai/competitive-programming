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

const int N = 1 << 17;
ll inf = 1e18;
vector<pair<int, int>> g[3 * N];
ll d[3 * N];

void dijkstra(int s) {
	fill(d, d + 3 * N, inf);
	d[s] = 0;
    priority_queue<pair<ll, int>> q;
    q.push({0, s});
    while (!q.empty()) {
		auto [d_v, v] = q.top(); q.pop(); d_v = -d_v;
        if (d[v] != d_v) continue;
        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push({-d[to], to});
            }
        }
    }
}

vector<int> get(int l, int r) {
	vector<int> res;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res.push_back(l++);
		if (r & 1) res.push_back(--r);
	}
	return res;
}

void add_edge(int v, int u, int w) { g[v].emplace_back(u, w); }
int mirror(int v) { return v + (v < N ? 2 * N : 0); }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, s; cin >> n >> q >> s; s = get(s - 1, s)[0];

	rep(p, 1, N) {
		add_edge(p, p << 1|0, 0);
		add_edge(p, p << 1|1, 0);
	}
	rep(p, 1, N) {
		add_edge(mirror(p << 1|0), mirror(p), 0);
		add_edge(mirror(p << 1|1), mirror(p), 0);
	}

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int v, u, w; cin >> v >> u >> w;
			u = get(u - 1, u)[0];
			v = get(v - 1, v)[0];
			add_edge(v, u, w);
		} else {
			int v, l, r, w; cin >> v >> l >> r >> w; --l;
			auto z = get(l, r);
			v = get(v - 1, v)[0];
			if (t == 2) for (int u : z) add_edge(v, u, w);
			else for (int u : z) add_edge(mirror(u), v, w);
		}
	}

	dijkstra(s);
	rep(u, 0, n) {
		int v = get(u, u + 1)[0];
		cout << (d[v] < inf ? d[v] : -1) << ' ';
	}
}