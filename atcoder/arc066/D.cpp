#include <bits/stdc++.h>
#include <atcoder/modint>

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


const int M = 1e9 + 7;
using mint = atcoder::static_modint<M>;
map<ll, mint> m;
mint f(ll n) {
	if (n == 0) return 1;
	if (n == 1) return 2;
	auto &x = m[n];
	
	if (!x.val()) {
		if (n & 1) {
			n >>= 1;
			x = 2 * f(n) + f(n - 1);
		} else {
			n >>= 1;
			x = 2 * f(n - 1) + f(n);
		}
	}
	return x;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n; cin >> n;
	cout << f(n).val();
}