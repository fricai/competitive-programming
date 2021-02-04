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

using vi = vector<int>;
struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

const int N = 1 << 7;
char g[N][N];

int h, w;
int hsh(int i, int j) { return w * i + j; }
int X(int s) { return s / w; }
int Y(int s) { return s % w; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> h >> w;
	int s = -1, t = -1;
	rep(i, 0, h) rep(j, 0, w) cin >> g[i][j];
	rep(i, 0, h) {
		rep(j, 0, w) {
			if (g[i][j] == 'S') s = hsh(i, j);
			if (g[i][j] == 'T') t = hsh(i, j);
		}
	}
	if (X(s) == X(t) || Y(s) == Y(t)) return cout << "-1\n", 0;
	Dinic d(2 * h * w);
	rep(i, 0, h) {
		rep(j, 0, w) {
			if (g[i][j] == '.') continue;
			int u = hsh(i, j);
			d.addEdge(u << 1|0, u << 1|1, 1);
			rep(k, 0, w) {
				if (k == j || g[i][k] == '.') continue;
				d.addEdge(u << 1|1, hsh(i, k) << 1|0, 1);
			}
			rep(k, 0, h) {
				if (k == i || g[k][j] == '.') continue;
				d.addEdge(u << 1|1, hsh(k, j) << 1|0, 1);
			}
		}
	}

	cout << d.calc(s << 1|1, t << 1|0);
}