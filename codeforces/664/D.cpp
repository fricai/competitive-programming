/*
	19/02/2020
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

const int N = 1 << 17, inf = 1e9;
int n;
vi g[N][2], cmp[N];
vector<bool> vis, color;

void print(const pair<int, vi> &ans) {
	if (ans.fi == inf) pr(-1);
	else {
		pr(ans.fi, '\n');
		trav(x, ans.se) pr(x, ' ');
	}
}

bool dfs(const int& u, const bool& c, const int& cnt, const bool& b = 0) {
	if (vis[u]) return color[u] == b;
	vis[u] = true; color[u] = b; cmp[cnt].pb(u);
	trav(v, g[u][!c]) if (!dfs(v, c, cnt, b)) return false;
	trav(v, g[u][c]) if (!dfs(v, c, cnt, !b)) return false;
	return true;
}

pair<int, vi> solve(bool c) {
	vis.assign(n, false); color.rsz(n);
	rep(i, 0, n) cmp[i].clear();
	vi ans;
	rep(u, 0, n) {
		if (!vis[u]) {
			if (!dfs(u, c, u)) return {inf, { }};
			int a[2] = {0, 0};
			trav(v, cmp[u]) ++a[color[v]];
			bool b = a[1] > a[0];
			trav(v, cmp[u]) if (color[v] != b) ans.pb(v + 1);
		}
	}
	return {sz(ans), ans};
}

signed main() {
	int m; re(n, m);
	rep(i, 0, m) {
		int u, v; re(u, v); --u; --v;
		char c; re(c); bool b = c != 'B';
		g[u][b].pb(v); g[v][b].pb(u);
	}
	print(min(solve(0), solve(1)));
}