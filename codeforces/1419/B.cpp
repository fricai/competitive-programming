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

const int N = 1 << 17;
const ll inf = 1e18;
ll f[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 1;
	while (true) {
		f[n] = 2 * f[n - 1] + (1ll << (2 * (n - 1)));
		if (f[n] > inf) break;
		++n;
	}
	int t; cin >> t;
	while (t--) {
		ll x; cin >> x;
		int i = 0;
		while (f[i] <= x) x -= f[i++];
		cout << i - 1 << '\n';
	}
}