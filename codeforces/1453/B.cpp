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

const int N = 1 << 18;
ll a[N];

ll solve() {
	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];

	ll s = 0;
	rep(i, 1, n) s += abs(a[i] - a[i - 1]);

	ll mx = 0;
	ckmax(mx, abs(a[0] - a[1]));
	rep(i, 1, n - 1) ckmax(mx, abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]) - abs(a[i - 1] - a[i + 1]));
	ckmax(mx, abs(a[n - 1] - a[n - 2]));

	cerr << '\n';
	return s - mx;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}