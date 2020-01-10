#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int N = 1 << 17;
int n;
ll m, v[N], a[N];

ll lcm(ll x, ll y) {
	return x / __gcd(x, y) * y;
}

ll solve() {
	rep(i, 0, n) {
		v[i] = a[i] & (-a[i]);
		a[i] /= 2;
	}
	rep(i, 0, n)
		if (v[0] != v[i])
			return 0;
	ll x = 1;
	rep(i, 0, n) {
		if (x > m) return 0;
		x = lcm(x, a[i]);
	}
	return (m + x) / (2LL * x);
}

signed main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	cin >> n >> m;
	rep(i, 0, n) cin >> a[i];
	cout << solve();
}