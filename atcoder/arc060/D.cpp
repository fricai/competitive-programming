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

ll f(ll b, ll n) {
	return n < b ? n : f(b, n / b) + (n % b);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, s; cin >> n >> s;
	if (s > n) return cout << -1, 0;
	if (s == n) return cout << n + 1, 0;
	for (ll b = 2; b * b <= n; ++b)
		if (f(b, n) == s) return cout << b, 0;
	
	vector<ll> ans;
	for (ll a = 1; a * a <= n; ++a) {
		if ((n - s) % a) continue;
		ll b = (n - s) / a + 1;
		if (f(b, n) == s) ans.push_back(b);
	}
	if (ans.empty()) return cout << -1, 0;
	cout << ans.back();
}