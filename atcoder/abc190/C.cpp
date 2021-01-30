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

	int n, m; cin >> n >> m;
	
	vector<int> a(m), b(m);
	rep(i, 0, m) cin >> a[i] >> b[i], --a[i], --b[i];
	
	int k; cin >> k;
	vector<int> c(k), d(k);
	rep(i, 0, k) cin >> c[i] >> d[i], --c[i], --d[i];

	int ans = 0;
	rep(S, 0, 1 << k) {
		vector<int> f(n, 0);

		rep(i, 0, k) ++f[(S >> i & 1) ? c[i] : d[i]];

		int cnt = 0;
		rep(i, 0, m) cnt += f[a[i]] && f[b[i]];
		ckmax(ans, cnt);
	}

	cout << ans;
}