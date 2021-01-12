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

const ll inf = 2e18;
const int N = 1 << 19;
ll a[N], b[N];
int n, r;
ll k;

bool f(ll x) {
	ll cur = 0, used = 0;
	rep(i, 0, n) b[i] = a[i];
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n && j - i <= r) cur += b[j], ++j;
		if (used > k) return false;
		if (cur < x) {
			b[j - 1] += x - cur;
			used += x - cur;
			cur = x;
		}
		if (r <= i) cur -= b[i - r];
	}
	return used <= k;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> r >> k;
	rep(i, 0, n) cin >> a[i];

	ll l = 0, r = inf;
	while (r - l > 1) {
		ll m = l + (r - l) / 2;
		(f(m) ? l : r) = m;
	}
	cout << l << '\n';
}