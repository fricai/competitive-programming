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

const int N = 1 << 17;
const ll inf = 1e18;
int a[N];
map<int, ll> memo[N];

ll f(ll n, ll k) {
	return ((n + k - 1) / k) * ((n + k - 1) / k) * (n % k) + (n / k) * (n / k) * (k - n % k);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k; cin >> n >> k;
	rep(i, 0, n) cin >> a[i];

	ll ans = 0;
	priority_queue<tuple<ll, int, int>> q;
	k -= n;
	rep(i, 0, n) q.push({f(a[i], 1) - f(a[i], 2), a[i], 1}), ans += 1ll * a[i] * a[i];
	while (k > 0) {
		auto [d, b, r] = q.top();
		q.pop();
		ans -= d; ++r;
		q.push({f(b, r) - f(b, r + 1), b, r});
		--k;
	}
	cout << ans;
}