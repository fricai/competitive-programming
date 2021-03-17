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

const int N = 200 + 10, X = 2e4 + 10;
bool prime[X];
int a[N];
vector<int> g[N];
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

vector<int> cycle[N];
bool vis[N];
int cnt = 0;
void dfs(int u) {
	vis[u] = 1;
	cycle[cnt].push_back(u);
	for (int v : g[u]) if (!vis[v]) dfs(v);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fill_n(prime, X, 1);
	prime[0] = prime[1] = 0;
	rep(i, 2, X) {
		if (!prime[i]) continue;
		for (int j = i * i; j < X; j += i) prime[j] = 0;
	}

	int n; cin >> n;
	int c = 0;
	rep(i, 0, n) {
		cin >> a[i]; 
		if (a[i] & 1) ++c;
		else --c;
	}
	if (c != 0) return cout << "Impossible", 0;

	Dinic D = n + 2;
	int s = n, t = n + 1;
	rep(i, 0, n) {
		if (a[i] & 1) D.addEdge(s, i, 2);
		else D.addEdge(i, t, 2);
	}
	rep(i, 0, n)
		if (a[i] & 1)
			rep(j, 0, n)
				if (prime[a[i] + a[j]])
					D.addEdge(i, j, 1);
	if (D.calc(s, t) != n) return cout << "Impossible", 0;

	rep(i, 0, n) {
		if (~a[i] & 1) continue;
		vector<int> cand;
		
		for (auto e : D.adj[i])
			if (e.flow()) g[i].push_back(e.to);
		assert(sz(g[i]) == 2);
		for (auto v : g[i]) g[v].push_back(i);
	}
	rep(i, 0, n) if (!vis[i]) dfs(i), ++cnt;

	cout << cnt << '\n';
	rep(i, 0, cnt) {
		cout << sz(cycle[i]) << ' ';
		for (auto x : cycle[i]) cout << x + 1 << ' ';
		cout << '\n';
	}
	
}