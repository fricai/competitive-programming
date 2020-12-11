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
int a[N];

ld solve() {
	int n, m; cin >> n >> m;
	rep(i, 0, n) cin >> a[i];
	int b = n;
	while (b > 0 && a[b - 1] == b) --b;
	ld q = 0;
	if (b == 0)  q = 1;
	rep(i, 0, m) {
		int r; ld p; cin >> r >> p;
		if (r >= b) q = (1 - p) * q + p;
	}
	return q;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(10);
	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}