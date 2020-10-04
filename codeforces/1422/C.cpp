#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define lb(x...) lower_bound(x)
#define ub(x...) upper_bound(x)

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }


const int M = 1e9 + 7;
ll bpow(ll a, ll b) {
	a %= M;
	b %= M - 1;
	if (b < 0) b += M - 1;
	ll res = 1;
	for ( ; b; b >>= 1, a = a * a % M)
		if (b & 1) res = res * a % M;
	return res;
}


const int N = 1 << 17;
ll a[N], p[N], q[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string t; cin >> t;
	int n = sz(t);
	rep(i, 0, n) a[i] = t[i] - '0';

	p[0] = q[0] = 0;
	rep(k, 0, n) p[k + 1] = (10 * p[k] + a[k]) % M;
	
	ll ans = 0, Q = 0;
	for (int j = 1; j <= n; ++j) {
		ans += j * (p[n] - bpow(10, n - j) * p[j] % M) % M;;
		ans += bpow(10, n - j) * Q % M;
		Q = (Q + p[j]) % M;
		ans %= M;
	}
	if (ans < 0) ans += M;
	cout << ans;
}