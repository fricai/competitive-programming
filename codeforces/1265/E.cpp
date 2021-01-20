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

const int M = (119 << 23) + 1, MX = 100 + 5;
int inv[MX];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	inv[1] = 1;
	rep(i, 2, MX) inv[i] = M - 1ll * M / i * inv[M % i] % M;
	
	int n; cin >> n;
	ll ans = 0;
	rep(i, 0, n) {
		int p; cin >> p;
		ans = 100 * (ans + 1) % M;
		ans = ans * inv[p] % M;
	} 
	cout << ans;
}