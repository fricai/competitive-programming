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

const ll inf = 1e18 + 20;


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	ll ans = inf;
	ll R_mn = inf, R_mx = 0, B_mn = inf, B_mx = 0;

	vector<pair<ll, ll>> p(n);
	for (auto &[x, y] : p) {
		cin >> x >> y;

		if (x > y) swap(x, y);
		ckmin(R_mn, x);
		ckmax(R_mx, x);
		ckmin(B_mn, y);
		ckmax(B_mx, y);
	}
	ckmin(ans, (R_mx - R_mn) * (B_mx - B_mn));

	// cerr << R_mx << ' ' << R_mn << ' ' << B_mx << ' ' << B_mn << '\n';

	sort(all(p));
	if (n == 1) return cout << 0, 0;

	R_mx = 0;
	R_mn = p[0].first;

	ll B_mn_deleted, B_mx_deleted;
	B_mn_deleted = B_mx_deleted = p[0].second;
	p.erase(begin(p));
	int to_delete = -1;
	rep(i, 0, n - 1) if (ckmax(R_mx, p[i].second)) to_delete = i;
	ckmin(B_mn_deleted, p[to_delete].first);
	ckmax(B_mx_deleted, p[to_delete].first);

	if (R_mx < B_mx_deleted) return cout << ans, 0;
	// cerr << R_mx << ' ' << R_mn << ' ' << B_mx_deleted << ' ' << B_mn_deleted << '\n';

	p.erase(begin(p) + to_delete);
	n -= 2;
	ll cur_mx = B_mx_deleted, cur_mn = B_mn_deleted;
	rep(i, 0, n + 1) {
		if (i != n) B_mx = max(p.back().first, cur_mx);
		else B_mx = cur_mx;

		if (i != n) B_mn = min(p[i].first, cur_mn);
		else B_mn = cur_mn;

		if (i != n) {
			ckmin(cur_mn, p[i].second);
			ckmax(cur_mx, p[i].second);
		}
		
		ckmin(ans, (R_mx - R_mn) * (B_mx - B_mn));
	}

	cout << ans;
}