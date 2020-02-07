/*
	07/02/2020
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

template <class T> using Tree = tree<T, null_type, less<T>, 
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
IO io = IO(false);

const int N = 1 << 13;
vi g[N];
int p[N], f[N], d[N];
pair<int, pii> q[N];
vector<pii> edge;

void dfs(int u, int w) {
	p[u] = w;
	d[u] = d[w] + 1;
	trav(v, g[u])
		if (v != w)
			dfs(v, u);
}

void set_color(int u, int v, int c) {
	if (u == v) return;
	if (d[u] < d[v]) {
		f[v] = c;
		set_color(u, p[v], c);
	} else {
		f[u] = c;
		set_color(p[u], v, c);
	}
}

int get_color(int u, int v) {
	if (u == v) return 1e6;
	if (d[u] < d[v])
		return min(f[v], get_color(u, p[v]));
	else
		return min(f[u], get_color(p[u], v));
}

signed main() {
	int n; re(n);
	rep(i, 1, n) {
		int u, v; re(u, v); --u, --v;
		edge.eb(u, v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0, 0);
	int m; re(m);
	rep(i, 0, m) re(q[i].se, q[i].fi);
	rep(i, 0, m) --q[i].se.fi, --q[i].se.se;
	sort(q, q + m);
	rep(u, 0, n) f[u] = 1e6;
	rep(i, 0, m) set_color(q[i].se.fi, q[i].se.se, q[i].fi);
	bool flag = false;
	rep(i, 0, m)
		if (get_color(q[i].se.fi, q[i].se.se) != q[i].fi)
			flag = true;
	if (flag) pr(-1);
	else
		rep(i, 0, n - 1)
			pr(p[edge[i].fi] == edge[i].se ? f[edge[i].fi] : f[edge[i].se], ' ');
}