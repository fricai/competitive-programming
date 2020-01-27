/*
	27 January 2020
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

namespace algebra {
	template<int m>
	class modular {
	private:
		int32_t r;
	public:
		modular(int64_t x = 0) {
			if (m <= x || m <= -x) x %= m;
			if (x < 0) x += m;
			r = x;
		}
		modular inv() const {
			modular<m> res{1}, b(*this);
			for (int e = m - 2; e; e >>= 1, b *= b)
				if (e & 1) res *= b;
			return res;
		}
		modular operator * (const modular &t) const { return 1LL * r * t.r % m; }
		modular operator / (const modular &t) const { return *this * t.inv(); }
		modular& operator += (const modular &t) {
			r += t.r;
			if (m <= r) r -= m;
			return *this;
		}
		modular& operator -= (const modular &t) {
			r -= t.r;
			if (r < 0) r += m;
			return *this;
		}
		modular operator + (const modular &t) const { return modular(*this) += t; }
		modular operator - (const modular &t) const { return modular(*this) -= t; }
		modular& operator *= (const modular &t) { return *this = *this * t; }
		modular& operator /= (const modular &t) { return *this = *this / t; }
		bool operator == (const modular &t) const { return r == t.r; }
		bool operator != (const modular &t) const { return r != t.r; }
		operator int32_t() const { return r; }
		template<int T> friend istream& operator >> (istream&, modular<T>&); 
		template<int T> friend ostream& operator << (ostream&, const modular<T>&);
	};
	template<int T>
	istream& operator >> (istream &in, modular<T> &x) {
		int64_t a; in >> a; x = modular<T>(a);
		return in;
	}
	template<int T>
	ostream& operator << (ostream &ou, const modular<T> &x) {
		return ou << x.r;
	}
	template<class T>
	T bpow(T a, ll b) {
		T res(1);
		while (b > 0) {
			if (b & 1)
				res *= a;
			a *= a;
			b >>= 1;
		}
		return res;
	}
}

using namespace input;
using namespace output;
IO io = IO(true);
const int M = 1e9 + 7;
using base = algebra::modular<M>;

const int N = 1 << 8;
base fac[N], ifac[N];

base nCr(ll n, ll k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * ifac[n - k] * ifac[k];
}

signed main() {
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	rep(i, 2, N)
		fac[i] = fac[i - 1] * base(i),
		ifac[i] = ifac[i - 1] / base(i);

	int n; base k; re(n, k);
	base res = 0;
	rep(i, 0, n) {
		base r = bpow(k, n - i) * bpow(k - base(1), i) - bpow(k - base(1), n);
		r = bpow(r, n);
		r *= nCr(n, i);
		if (i & 1) res -= r;
		else res += r;
	}
	pr(res);
}