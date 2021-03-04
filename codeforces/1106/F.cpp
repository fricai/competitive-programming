#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#pragma GCC optimize ("trapv")

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

const int K = 1 << 7, M = (119 << 23) + 1;

void add(int &x, int y, int p = M) { x += y; if (p <= x) x -= p; }

using vi = vector<int>;
vector<vi> operator*(const vector<vi> &a, const vector<vi> &b) {
	vector<vi> c(sz(a), vi(sz(b[0])));
	rep(i, 0, sz(a))
		rep(j, 0, sz(b[0]))
			rep(k, 0, sz(b))
				add(c[i][j], (ll) a[i][k] * b[k][j] % (M - 1), M - 1);
	return c;
}

vector<vi> binpow(vector<vi> a, int n) {
	vector<vi> res(sz(a), vi(sz(a)));
	rep(i, 0, sz(a)) res[i][i] = 1;
	for (; n; n >>= 1, a = a * a)
		if (n & 1) res = res * a;
	return res;
}

ll binpow(ll a, int n) {
	ll res = 1;
	for ( ; n; n >>= 1, a = a * a % M)
		if (n & 1) res = res * a % M;
	return res;
}

ll modlog(ll a, ll b, ll m) {
	ll n = (ll) sqrt(m) + 1, e = 1, f = 1, j = 1;
	unordered_map<ll, ll> A;
	while (j <= n && (e = f = e * a % m) != b % m)
		A[e * b % m] = j++;
	if (e == b % m) return j;
	if (gcd(m, e) == gcd(m, b)) 
		rep(i, 2, n + 2)
			if (A.count(e = e * f % m))
				return n * i - A[e];
	return -1;
}

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

const int q = 5;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k; cin >> k;
	vector<int> b(k);
	for (auto &x : b) cin >> x;
	
	int n, m; cin >> n >> m;
	
	vector<vi> A(k, vi(k, 0));
	rep(i, 1, k) A[i - 1][i] = 1;
	A.back() = b;
	reverse(all(A.back()));
	A = binpow(A, n - k);

	int s = A.back().back();
	int x = modlog(q, m, M);
	assert(x != -1);

	ll a, garbage, g = euclid(s, M - 1, a, garbage);
	if (x % g != 0) return cout << -1, 0;
	if (a < 0) {
		ll k = (-a) / ((M - 1) / g) + 1;
		a += k * (M - 1) / g;
		assert(a >= 0);
		assert(a - (M - 1) / g < 0);
	}
	a = a * x / g % (M - 1);
	cout << binpow(q, a) << '\n';
}