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
const ll inf = 1e10;
ll t[N], x[N];

int solve() {
	int n; cin >> n;
	rep(i, 0, n) cin >> t[i] >> x[i];
	t[n] = inf;

	int res = 0;
	ll cur = 0, dest = 0;
	rep(i, 0, n) {
		if (cur == dest) dest = x[i];
		ll nxt = cur;
		ll d = min(abs(dest - cur), t[i + 1] - t[i]);
		nxt += cur < dest ? +d : -d;
		if (min(cur, nxt) <= x[i] && x[i] <= max(cur, nxt)) ++res;
		cur = nxt;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}