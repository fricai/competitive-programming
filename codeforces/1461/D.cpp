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
set<ll> s;
int a[N];
ll p[N];

void dumb(int l, int r) {
	s.insert(p[r] - p[l]);
	int mid = (a[l] + a[r - 1]) / 2;
	int m = upper_bound(a + l, a + r, mid) - a;
	if (m == r) return;
	dumb(l, m); dumb(m, r);
}

void solve() {
	int n, q; cin >> n >> q;
	rep(i, 0, n) cin >> a[i];
	sort(a, a + n);
	s.clear();
	rep(i, 0, n) p[i + 1] = p[i] + a[i];
	dumb(0, n);
	rep(i, 0, q) {
		int v; cin >> v;
		cout << (s.count(v) ? "Yes\n" : "No\n");
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}