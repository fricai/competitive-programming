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

const int N = 1 << 18, B = 1 << 8, A = 26;
const ll inf = 1e18;
int pi[N];
ll f[B];
string g[B];

int n;
string s;

using V = vector<ll>;
V freq[B];

V& operator+=(V &x, const V &y) {
	assert(sz(x) == sz(y));
	rep(i, 0, sz(x)) x[i] += y[i];
	return x;
}
V operator+(V x, const V &y) { return x += y; }

V operator-(V x, const V &y) {
	assert(sz(x) == sz(y));
	rep(i, 0, sz(x)) x[i] -= y[i];
	return x;
}

V solve(ll r) {	
	int k = 0; while (f[k] < r) ++k;
	V res(A, 0);
	while (k > 1) {
		if (r <= f[k - 1]) --k;
		else {
			res += freq[k - 1];
			r -= f[k - 1];
			k -= 2;
		}
	}
	rep(i, 0, r) ++res[g[k][i] - 'a'];
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string t; ll l, r; cin >> t >> l >> r;

	n = sz(t) / 2;
	s = t.substr(0, n);
	
	for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }

	g[0] = s;
	g[1] = s + s.substr(0, n - pi[n - 1]);
	rep(k, 0, 2) {
		freq[k].assign(A, 0);
		f[k] = sz(g[k]);
		for (auto c : g[k]) ++freq[k][c - 'a'];
	}

	for (int i = 2; f[i - 1] <= r; ++i) {
		f[i] = f[i - 1] + f[i - 2];
		freq[i] = freq[i - 1] + freq[i - 2];
	}

	auto res = solve(r) - solve(l - 1);
	for (auto x : res) cout << x << ' ';
}