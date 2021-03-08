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

const int M = (119 << 23) + 1;

int binpow(ll a, ll b) {
	ll res = 1;
	for (; b; b >>= 1, a = a * a % M)
		if (b & 1) res = res * a % M;
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m, l, r; cin >> n >> m >> l >> r;
	r -= --l;

	ll ans = binpow(r, n * m);
	if ((n * m) % 2 == 0) {	
		ans += r & 1;
		ans = ans * (M + 1) / 2 % M;
	}
	cout << ans;
}