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

const int N = 1 << 20, M = 998244353;
ll f[N], fi[N];

ll bpow(ll a, ll b) {
	ll res = 1;
	for (; b; b >>= 1, a = a * a % M)
		if (b & 1) res = res * a % M;
	return res;
}

int nCr(int n, int k) {
	if (k < 0 || k > n) return 0;
	return (ll) f[n] * fi[k] % M * fi[n - k] % M;
}

int add(int x, int y) {
	x += y;
	if (M <= x) x -= M;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) x += M;
	return x;
}
int mul(ll x, ll y) { return x * y % M; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	f[0] = 1;
	rep(i, 1, N) f[i] = i * f[i - 1] % M;
	fi[N - 1] = bpow(f[N - 1], M - 2);
	per(i, 1, N) fi[i - 1] = i * fi[i] % M;
	
	ll n; cin >> n;

	int a = 0, b = 0;
	for (int i = 1; i <= n; ++i) {
		int del = mul(nCr(n, i), bpow(3, n * (n - i) + i));
		if (i & 1) a = add(a, del);
		else a = sub(a, del);	
	}
	for (int i = 1; i <= n; ++i) {
		int x = bpow(3, n - i);
		int del = mul(nCr(n, i), sub(bpow(x - 1, n), bpow(x, n)));
		if (i & 1) b = add(b, del);
		else b = sub(b, del);
	}
	a = mul(a, 2);
	b = mul(b, 3);
	cout << add(a, b) << '\n';
}