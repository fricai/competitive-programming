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

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = 119 << 23 | 1, root = 62, M = mod; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
using vl = vector<ll>;
using vi = vector<int>;

int mul(ll x, int y) { return x * y % M; }
int bpow(int x, ll b) {
	int res = 1;
	for (; b; b >>= 1, x = mul(x, x))
		if (b & 1) res = mul(res, x);
	return res;
}
int add(int x, int y) { return x += y, x < M ? x : x - M; }
int sub(int x, int y) { return x -= y, x < 0 ? x + M : x; }

void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, bpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = bpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; ll m; cin >> n >> m;
	m %= M - 1;
	
	vl f(n + 1), g(n + 1), p(n + 1);
	for (auto &x : p) cin >> x;
	
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
		f[i] = mul(f[i - 1], i);
	g.back() = bpow(f.back(), M - 2);
	for (int i = n; i > 0; --i)
		g[i - 1] = mul(g[i], i);

	vector b(rall(g));
	auto Qi = [&](const vl &p) {
		vl a(n + 1);
		for (int i = 0; i <= n; ++i)
			a[i] = mul(p[i], f[i]);
		a = conv(a, b);
		a = vector(end(a) - n - 1, end(a));
		for (int i = 0; i <= n; ++i)
			a[i] = mul(a[i], g[i]);
		return a;
	};
	auto Q = [&](const vl &p) {
		vl a(n + 1);
		for (int i = 0; i <= n; ++i) {
			a[i] = mul(p[i], f[i]);
			if (i & 1) a[i] = M - a[i];
		}
		a = conv(a, b);
		a = vector(end(a) - n - 1, end(a));
		for (int i = 0; i <= n; ++i) {
			a[i] = mul(a[i], g[i]);
			if (i & 1) a[i] = M - a[i];
		}
		return a;
	}; 
	p = Qi(p);
	for (int i = 0; i <= n; ++i)
		p[i] = mul(p[i], bpow(i + 1, M - m - 1));
	p = Q(p);

	for (auto &x : p) {
		if (M <= x) x -= M;
		cout << x << ' ';
	}
	cout << '\n';
}