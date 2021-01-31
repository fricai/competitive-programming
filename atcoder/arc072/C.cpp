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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	ll res = 1e18, cur = 0;
	for (ll sum = 0, i = 0, sign = +1; i < n; ++i, sign *= -1) {
		sum += a[i];
		if (sign < 0 && sum >= 0) cur += sum + 1, sum = -1;
		else if (sign > 0 && sum <= 0) cur += 1 - sum, sum = +1;
	}
	ckmin(res, cur);

	cur = 0;
	for (ll sum = 0, i = 0, sign = -1; i < n; ++i, sign *= -1) {
		sum += a[i];
		if (sign < 0 && sum >= 0) cur += sum + 1, sum = -1;
		else if (sign > 0 && sum <= 0) cur += 1 - sum, sum = +1;
	}
	ckmin(res, cur);

	cout << res;
}