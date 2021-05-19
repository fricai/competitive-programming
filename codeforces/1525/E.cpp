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

const int N = 23, M = 5e4 + 5, mod = 998244353;

int mul(ll x, int y) { return (x * y) % mod; }
int add(int x, int y) { return x += y, x < mod ? x : x - mod; }
int sub(int x, int y) { return x -= y, x < 0 ? x + mod : x; }
int bpow(int a, ll b) {
	int res = 1;
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1) res = mul(res, a);
	return res;
}
int inv(int a) { return bpow(a, mod - 2); }

int d[N][M], f[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	rep(i, 0, n) rep(j, 0, m) cin >> d[i][j];

	int fac = 1;
	for (int i = 1; i <= n; ++i)
		fac = mul(fac, i);
	
	int ans = 0;
	rep(j, 0, m) {
		fill_n(f, N, 0);
		rep(i, 0, n) ++f[n - d[i][j] + 1];
		
		int del = 0, cur = 1;
		rep(i, 0, n) {
			assert(del >= 0);

			del += f[i];
			cur = mul(cur, del);
			if (del) --del;
		}
		
		ans = add(ans, sub(fac, cur));
	}
	
	cout << mul(ans, inv(fac)) << '\n';
}