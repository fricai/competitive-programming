/*
	30 January 2020
	islingr
*/

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

template<class T> using ost = tree<T, null_type, less<T>, 
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
	}
	IO(bool b, string s) {
		if (b) fastio();
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

signed main() {
    int t; re(t);
    while (t--) {
        int n; ll x; re(n, x);
        string s; re(s);
        ll b = 0;
        trav(c, s)
            if (c == '0') ++b;
            else --b;
        if (b == 0) {
            int ans = 0;
            ll r = 0;
            if (x == 0) ans = -1;
            trav(c, s) {
                if (c == '0') ++r;
                else --r;
                if (x == r) ans = -1;
            }
            pr(ans, '\n');
        } else {
            ll ans = 0;
            if (x == 0) ++ans;
            ll r = 0;
            trav(c, s) {
                if (c == '0') ++r;
                else --r;
                if ((x - r) % b == 0)
                    if ((x - r) / b >= 0)
                        ++ans;
            }
            pr(ans, '\n');
        }
    }
}