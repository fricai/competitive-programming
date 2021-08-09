#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M = 1e9 + 7;

int mul(ll x, int y) { return x * y % M; }
int add(int x, int y) { return x += y, x < M ? x : x - M; }
int sub(int x, int y) { return x -= y, x < 0 ? x + M : x; }
int bpow(int a, ll b) {
	ll res = 1;
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1) res = mul(res, a);
	return res;
}

int solve() {
	int n, k; cin >> n >> k;
	
	vector<int> f(k + 1);
	f[0] = 1;
	
	int p = bpow(2, n);
	int q = sub(bpow(2, n - 1), 1);
	int r = add(bpow(2, n - 1), 1);
		
	if (n & 1)
		for (int i = 1; i <= k; ++i)
			f[i] = mul(r, f[i - 1]);
	else
		for (int i = 1, z = 1; i <= k; ++i, z = mul(z, p))
			f[i] = add(z, mul(q, f[i - 1]));
	return f[k];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}