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
IO io = IO(false);

class dsu {
	vi nxt, rnk, cmp;
	vector<pii> edg;
public:
	void push(int u, int v) {
		cmp.pb(u); cmp.pb(v);
		edg.eb(u, v);
	}
	int hsh(int u) {
		return lb(all(cmp), u) - begin(cmp);
	}
	void init() {
		if (cmp.empty()) return;
		sort(all(cmp)); cmp.erase(unique(all(cmp)), end(cmp));
		nxt.assign(sz(cmp), -1); rnk.assign(sz(cmp), 0);
		trav(e, edg) unite(e.fi, e.se);
	}
	int head(int u) {
		return nxt[u] == -1 ? u : nxt[u] = head(nxt[u]);
	}
	void unite(int u, int v) {
		int i = hsh(u), j = hsh(v);
		u = i; v = j;
		u = head(u); v = head(v);
		if (u == v) return;
		if (rnk[u] < rnk[v]) nxt[u] = v;
		else {
			nxt[v] = u;
			if (rnk[u] == rnk[v]) ++rnk[u];
		}
	}
	bool same(int u, int v) {
		int i = hsh(u), j = hsh(v);
		if (i == sz(cmp) || j == sz(cmp) || cmp[i] != u || cmp[j] != v)
			return false;
		return head(i) == head(j);
	}
};

signed main() {
	int n, m; re(n, m);
	dsu d[m]; vi e[n];
	rep(i, 0, m) {
		int u, v, c; re(u, v, c); --c; --u; --v;
		d[c].push(u, v);
		e[u].pb(c); e[v].pb(c);
	}
	rep(u, 0, n) sort(all(e[u])), e[u].erase(unique(all(e[u])), end(e[u]));
	rep(c, 0, m) d[c].init();

	map<pii, int> ans;
	int q; re(q);
	while (q--) {
		int u, v; re(u, v); --u; --v;
		if (sz(e[u]) > sz(e[v])) swap(u, v);
		auto it = ans.find({u, v});
		int a = 0;
		if (it != ans.end()) a = it->se;
		else {
			trav(c, e[u]) if (d[c].same(u, v)) ++a;
			ans[{u, v}] = a;
		}
		pr(a, '\n');
	}
}