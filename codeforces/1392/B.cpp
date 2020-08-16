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

const int N = 1 << 20;
int a[N];

void solve() {
	ll n, k; cin >> n >> k;
	rep(i, 0, n) cin >> a[i];
	int mx = *max_element(a, a + n);
	int mn = *min_element(a, a + n);
	if (k == 0) {
		rep(i, 0, n) cout << a[i] << ' ';
		cout << '\n';
	} else {
		if (k & 1) {
			rep(i, 0, n) cout << mx - a[i] << ' ';
			cout << '\n';
		} else {
			rep(i, 0, n) cout << a[i] - mn << ' ';
			cout << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();	
}