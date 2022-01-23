#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int mod = 1e9 + 7, N = 1e6 + 10, inv2 = (mod + 1) / 2;
int f[N], fi[N];
int add(int x, int y) { return x += y, x < mod ? x : x - mod; }
int sub(int x, int y) { return x -= y, x < 0 ? x + mod : x; }
int& inc(int &x, int y) { return x += y, x < mod ? x : (x -= mod); }
int& dec(int &x, int y) { return x -= y, x < 0 ? (x += mod) : x; }
int mul(ll x, int y) { return x * y % mod; }
int C(int n, int r) { return mul(f[n], mul(fi[r], fi[n - r])); }
int bpow(ll a, ll b) {
	ll res = 1;
	for (; b; b >>= 1, a = a * a % mod)
		if (b & 1) res = res * a % mod;
	return res;
}

int solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> f(n);
	rep(i, 0, n) f[i] = C(n, i);
	rep(i, 1, n) inc(f[i], f[i - 1]);
	rep(i, 1, n) inc(f[i], f[i - 1]);
	return mul(k, mul(bpow(inv2, n - 1), f[m - 1]));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = fi[0] = 1;
	rep(i, 1, N) f[i] = mul(i, f[i - 1]);
	fi[N - 1] = bpow(f[N - 1], mod - 2);
	per(i, 1, N) fi[i - 1] = mul(i, fi[i]);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
