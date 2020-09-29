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
template<class T> T gcd(T a, T b) { return b != T(0) ? gcd(b, a % b) : a; }

const int N = 1 << 19;
int a[N], n;

ll ans = 0;

void add(int i) {
	if (!i || i > n) return;
	if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans += a[i];
	if (a[i] < a[i - 1] && a[i] < a[i + 1]) ans -= a[i];
}

void sub(int i) {
	if (!i || i > n) return;
	if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans -= a[i];
	if (a[i] < a[i - 1] && a[i] < a[i + 1]) ans += a[i];
}

void solve() {
	int q; cin >> n >> q;
	
	a[0] = a[n + 1] = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	ans = 0;
	for (int i = 1; i <= n; ++i) add(i);

	cout << ans << '\n';
	while (q--) {
		int l, r; cin >> l >> r;
		set<int> s = {l - 1, l, l + 1, r - 1, r, r + 1};
		for (int x : s) sub(x);
		swap(a[l], a[r]);
		for (int x : s) add(x);
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while (t--) solve();
}