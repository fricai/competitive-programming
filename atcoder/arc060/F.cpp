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

struct H {
	typedef uint64_t ull;
	ull x; H(ull x = 0) : x(x) {}
#define OP(O,A,B) H operator O(H o) { ull r = x; asm \
	(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); return r; }
	OP(+,,"d"(o.x)) OP(*,"mul %1\n", "r"(o.x) : "rdx")
	H operator-(H o) { return *this + ~o.x; }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval() { }
	HashInterval(string& str) : ha(sz(str) + 1), pw(ha) {
		pw[0] = 1;
		rep(i, 0, sz(str))
			ha[i + 1] = ha[i] * C + str[i],
			pw[i + 1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
} hasher;

const int N = 1 << 19;
vector<int> divisors[N];
string s;

vector<bool> for_prefix[N], for_suffix[N];

bool prefix_good(int i) {
	for (int d : divisors[i]) if (for_prefix[d][i / d - 1]) return false;
	return true;
}

bool suffix_good(int i) {
	for (int d : divisors[i]) if (for_suffix[d][i / d - 1]) return false;
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	int n = sz(s);

	for (int d = 1; d <= n; ++d)
		for (int j = 2 * d; j <= n; j += d)
			divisors[j].push_back(d);
	
	bool all_equal = true;
	rep(i, 1, n) all_equal &= s[i] == s[i - 1];
	if (all_equal) return cout << n << "\n1", 0;

	hasher = s;
	for (int d = 1; d <= n; ++d) {
		for_prefix[d] = {1};
		for (int i = d; i + d <= n; i += d)
			for_prefix[d].push_back(for_prefix[d].back() && (hasher.hashInterval(0, d) == hasher.hashInterval(i, i + d)));
	}

	for (int d = 1; d <= n; ++d) {
		for_suffix[d] = {1};
		for (int i = n - d; i - d >= 0; i -= d)
			for_suffix[d].push_back(for_suffix[d].back() && (hasher.hashInterval(n - d, n) == hasher.hashInterval(i - d, i)));
	}

	if (suffix_good(n)) return cout << "1\n1", 0;

	int cnt = 0;
	rep(i, 1, n) cnt += prefix_good(i) && suffix_good(n - i);
	cout << "2\n" << cnt;
}