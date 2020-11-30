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

const int N = 4;
const ll inf = 5e9;
ll X[N], Y[N], x[N], y[N];
int ord[N];

ll f(ll s) {
	rep(i, 0, N) x[i] = X[ord[i]], y[i] = Y[ord[i]];
	x[3] -= s; y[3] -= s;
	x[2] -= s; y[1] -= s;
	sort(x, x + N); sort(y, y + N);
	ll res = 0;
	rep(i, 0, N) res += abs(x[i] - x[1]) + abs(y[i] - y[1]);
	return res;
}

ll solve() {
	rep(i, 0, N) cin >> X[i] >> Y[i];

	iota(ord, ord + N, 0);
	ll res = inf;
	do {
		ll l = 0, r = inf;
		while (l < r) {
			ll mid = (l + r) / 2;
			if (f(mid) < f(mid + 1)) r = mid;
			else l = mid + 1;
		}
		ckmin(res, f(l));
	} while (next_permutation(ord, ord + N));
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';	
}