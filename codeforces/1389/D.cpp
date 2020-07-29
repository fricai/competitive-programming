#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define trav(e, x) for (auto &e : x)
#define eb(x...) emplace_back(x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll inf = 1e18;

ll solve() {
	int n; ll k, al, ar, bl, br;
	cin >> n >> k >> al >> ar >> bl >> br;
	k -= n * max(0ll, min(ar, br) - max(al, bl));
	if (k <= 0) return 0;	
	if (al > bl) swap(al, bl), swap(ar, br);
	ll ans = inf, cur = 0;
	ll join = max(0ll, bl - ar), del = (bl - al) + abs(br - max(bl, ar));
	rep(i, 0, n) {
		cur += join;
		if (del <= k) cur += del, k -= del;
		else cur += k, k = 0;
		ckmin(ans, cur + 2 * k);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}