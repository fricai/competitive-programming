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

const int N = 100 + 2, A = 100 + 2, M = 1e9 + 7;

int add(int x, int y) { return x += y, x < M ? x : x - M; }
int sub(int x, int y) { return x -= y, x < 0 ? x + M : x; }
int mul(ll x, int y) { return x * y % M; }
int bpow(int x, int y) {
	int res = 1;
	for (; y; y >>= 1, x = mul(x, x))
		if (y & 1) res = mul(res, x);
	return res;
}

int dp[N][A * N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> c(n), b(n - 1);
	for (auto &x : c) cin >> x;
	for (auto &x : b) cin >> x;

	int q; cin >> q;
	assert(q == 1);

	ll x; cin >> x;

	vector<int> bp(n, 0);

	int cur = 0;
	rep(i, 1, n) {
		cur += b[i - 1];
		bp[i] = bp[i - 1] + cur;
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i)
		rep(a, 0, A * n)
			for (int b = 0; b <= c[i] && a + b < A * n; ++b)
				if ((a + b) - bp[i] >= (i + 1) * x)
					dp[i + 1][a + b] = add(dp[i + 1][a + b], dp[i][a]);
	
	int res = 0;
	rep(a, 0, A * n) res = add(res, dp[n][a]);
	cout << res << '\n';
}