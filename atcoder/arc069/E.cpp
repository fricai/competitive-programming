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

const int N = 1 << 17;
ll a[N];
int ord[N];
ll ans[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	rep(i, 0, n) cin >> a[i], ord[i] = i;
	sort(ord, ord + n, [&](int x, int y) {
		return a[x] > a[y];
	});
	ord[n] = n;
	for (int i = 0, j = 0, k = 0, mn = n; i < n; i = j) {
		while (a[ord[i]] == a[ord[j]]) ++j;
		k += j - i;
		rep(r, i, j) ckmin(mn, ord[r]);
		ans[mn] += k * (a[ord[i]] - a[ord[j]]);
	}
	
	rep(i, 0, n) cout << ans[i] << '\n';
}