/*
	04/03/2020
	islingr
*/

#include <cassert>
#include <cmath>

#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <iostream>
#include <iomanip>

#include <algorithm>
#include <complex>
#include <chrono>
#include <random>
#include <utility>

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
		pr("(", p.first, ", ", p.second, ")");
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

using namespace input;
using namespace output;
IO io = IO(true);

int n;

struct point {
	int x, y;
	point() { }
	point(int a, int b) : x{a}, y{b} { }
	operator int() { return max(-1, n * x + y); }
	point operator+(const point &p) { return {x + p.x, y + p.y}; }
};
const vector<point> d = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
const vector<char> label = {'D', 'U', 'R', 'L'};
vi g;
vector<char> ans;

bool check(int x) {
	return 0 <= x && x < n;
}
bool check(point p) {
	return check(p.x) && check(p.y);
}

void dfs(point u, char c) {
	if (ans[u]) return;
	ans[u] = c;
	rep(i, 0, 4) {
		point v = u + d[i];
		if (!check(v) || g[u] != g[v]) continue;
		dfs(v, label[i]);
	}
}

void idfs(point u) {
	if (ans[u]) return;
	rep(i, 0, 4) {
		point v = u + d[i];
		if (!check(v) || g[v] != -1) continue;
		ans[u] = label[i ^ 1];
		idfs(v);
		break;
	}
}

bool solve() {
	re(n); g.rsz(n * n); ans.rsz(n * n);
	vector<point> X, I;
	rep(x, 0, n) rep(y, 0, n) {
		int a, b; re(a, b);
		if (a != -1) --a, --b;
		point u(x, y), v(a, b);
		g[u] = v;
		if (u == v) X.eb(u);
		if (v == -1) I.eb(u);
	}
	trav(u, X) dfs(u, 'X');
	trav(u, I) idfs(u);
	rep(i, 0, n * n) if (!ans[i]) return false;
	return true;
}

signed main() {
	if (solve()) {
		pr("VALID\n");
		rep(x, 0, n) {
			rep(y, 0, n) pr(ans[point(x, y)]);
			pr('\n');
		}
	} else pr("INVALID");
}