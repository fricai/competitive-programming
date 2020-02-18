/*
	17/02/2020
	islingr
*/

#pragma region Boilerplate
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front
#define bk back
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
#define fi first
#define se second

#define rep(i, a, b) for (auto i = (a); i < (b); ++i) // [a, b)
#define per(i, a, b) for (auto i = (b) - 1; i >= (a); --i) // (b, a]
#define trav(e, x) for (auto &e : x)

template<class T>
bool ckmin(T& a, const T& b) { 
	return a > b ? a = b, 1 : 0;
}
template<class T>
bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0;
}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

template <class T> using ost = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key
#define fbo find_by_order

namespace helper {
	template<class T, class = decltype(begin(declval<T>()))>
	inline constexpr auto is_iterable(int) { return true_type{}; }

	template<class>
	inline constexpr auto is_iterable(unsigned) { return false_type{}; }
}

namespace input {
	void re(string &s) { cin >> s; }

	template<class T> void re(T& x);
	template<class P, class Q> void re(pair<P, Q>&);
	template<class T, class... Ts> void re(T& t, Ts&... ts);
	
	template<class T> void re(T& x, false_type) { cin >> x; }
	template<class T> void re(T& x, true_type) {
		for (auto &v : x) re(v);
	}
	template<class T> void re(T& x) {
		re(x, helper::is_iterable<T>(0));
	} 
	template<class P, class Q>
	void re(pair<P, Q> &p) {
		re(p.first, p.second);
	}
	template<class T, class... Ts> void re(T& t, Ts&... ts) {
		re(t);
		re(ts...);
	}
}

namespace output {
	template <typename T> void pr(const T&);
	template<class T, class... Ts> void pr(const T&, const Ts&...);

	template<class S, class T>
	void pr(const pair<S, T> &p) {
		pr("(", p.first, ",", p.second, ")");
	}

	template<class T>
	void pr(queue<T> q) {
		pr("{"); bool c = false;
		while (!q.empty())
			pr(c ? ", " : "", q.front()),
			q.pop(),
			c = true;
		pr("}");
	}
	template<class T>
	void pr(priority_queue<T> q) {
		pr("{"); bool c = false;
		while (!q.empty())
			pr(c ? ", " : "", q.top()),
			q.pop(),
			c = true;
		pr("}");
	}
	template<class T>
	void pr(stack<T> s) {
		pr("{"); bool c = false;
		while (!s.empty())
			pr(c ? ", " : "", s.top()),
			s.pop(),
			c = true;
		pr("}");
	}
	void pr(const string &s) { cout << s; }

	template<typename T>
	void pr(const T& x, false_type) { cout << x; }

	template<typename T>
	void pr(const T& x, true_type) {
		pr("{"); bool f = false;
		for (const auto &v : x)
			pr(f ? ", " : "", v),
			f = true;
		pr("}");
	}

	template <typename T>
	void pr(const T& x) {
		pr(x, helper::is_iterable<T>(0));
	}
	
	template<class T, class... Ts>
	void pr(const T& t, const Ts&... ts) { pr(t); pr(ts...); }
	
	void pc() { pr("]\n"); } // debug w/ commas

	template<class T, class... Ts>
	void pc(const T& t, const Ts&... ts) { 
		pr(t);
		if (sizeof...(ts)) pr(", ");
		pc(ts...); 
	}

	#define dbg(x...) pr("[", #x, "] = ["), pc(x);
}

struct IO {
	IO(bool b) {
		if (b) fastio();
		cout << fixed << setprecision(numeric_limits<ld>::digits10);
	}
	IO(bool b, string s) : IO(b) {
		setIn(s + ".in");
		setOut(s + ".out");
	}
	void fastio() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
	}
	void setIn(string s) { freopen(s.c_str(), "r", stdin); }
	void setOut(string s) { freopen(s.c_str(), "w", stdout); }
};
#pragma endregion 

using namespace input;
using namespace output;
IO io = IO(true);

class dsu {
	vi nxt, rnk;
public:
	dsu(int n = 0) : nxt(n), rnk(n, 0) {
		rep(i, 0, n) nxt[i] = i;
	}
	void resize(int a) {
		int n = sz(nxt); nxt.rsz(a);
		rep(i, n, a) nxt[i] = i;
		rnk.rsz(a, 0);
	}
	int head(int u) {
		return nxt[u] == u ? u : nxt[u] = head(nxt[u]);
	}
	void unite(int u, int v) {
		u = head(u); v = head(v);
		if (u == v) return;
		if (rnk[u] < rnk[v])
			nxt[u] = v;
		else {
			nxt[v] = u;
			if (rnk[u] == rnk[v])
				++rnk[u];
		}
	}
	bool same(int u, int v) {
		return head(u) == head(v);
	}
};

const int N = 1 << 18, B = 19, inf = 1e9;
int n, k, r;
vi g[N << 1], s;;
int a[N << 1][B],  d[N << 1];
dsu D;

void bfs() {
	vector<int> dist(2 * n, inf);
	vector<bool> vis(2 * n, false);
	D.rsz(2 * n);
	queue<tuple<int, int, int>> q;
	trav(x, s) q.push({x, x, 0}), dist[x] = 0;
	while (!q.empty()) {
		int u, p, d; tie(u, p, d) = q.ft(); q.pop();
		if (d > k) continue;
		D.unite(u, p);
		if (vis[u]) continue; vis[u] = true;
		ckmin(dist[u], d);
		trav(v, g[u])
			q.push({v, u, dist[u] + 1});
	}
}

void dfs(int u, int p) {
	a[u][0] = p; d[u] = d[p] + 1;
	trav(v, g[u]) if (v != p) dfs(v, u);
}

int jump(int u, int b) {
	for (int s = 0; b; ++s, b >>= 1)
		if (b & 1)
			u = a[u][s];
	return u;
}

int lca(int u, int v) {
	if (d[u] > d[v]) u = jump(u, d[u] - d[v]);
	else v = jump(v, d[v] - d[u]);
	if (u == v) return u;
	per(s, 0, B)
		if (a[u][s] != a[v][s])
			u = a[u][s], v = a[v][s];
	return a[u][0];
}

bool check(int u, int v) {
	int l = lca(u, v), t = d[u] + d[v] - 2 * d[l];
	if (t <= 2 * k) return true;
	if (d[u] < d[v]) swap(u, v);
	if (d[v] - d[l] < k) v = jump(u, t - k);
	else v = jump(v, k);
	u = jump(u, k);
	return D.same(u, v);
}

signed main() {
	re(n, k, r);
	rep(i, 1, n) {
		int u, v; re(u, v);
		g[u].pb(i + n);
		g[i + n].pb(u);
		g[v].pb(i + n);
		g[i + n].pb(v);
	}

	s.rsz(r); re(s);
	bfs(); dfs(1, 1);
	rep(i, 1, B) rep(u, 1, 2 * n) a[u][i] = a[a[u][i - 1]][i - 1];

	int q; re(q);
	while (q--) {
		int u, v; re(u, v);
		pr(check(u, v) ? "YES\n" : "NO\n");
	}
}