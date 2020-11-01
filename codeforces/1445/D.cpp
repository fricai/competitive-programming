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

const int M = (119 << 23) + 1;

ll bpow(ll a, ll b) {
	ll res = 1;
	for ( ; b; b >>= 1, a = a * a % M)
		if (b & 1) res = res * a % M;
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(2 * n);

	for (int &x : a) cin >> x;
	
	sort(all(a));

	ll res = 0;
	rep(i, 0, n) res += a[i + n] - a[i];
	res %= M;

	ll p = 1;
	for (int i = 1; i <= n; ++i) p = p * i % M;
	p = bpow(p, 2 * (M - 2));
	for (int i = 1; i <= 2 * n; ++i) p = p * i % M;

	cout << res * p % M;
}