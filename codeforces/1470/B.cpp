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

const int N = 1 << 19, MX = 1 << 20;
int a[N], lp[MX];
vector<int> pr;

void solve() {
	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];

	rep(i, 0, n) {
		int pri = 1;
		while (a[i] != 1) {
			int z = a[i]; bool k = 0;
			while (lp[z] == lp[a[i]]) z /= lp[z], k ^= 1;
			if (k) pri *= lp[a[i]];
			a[i] = z;
		}
		a[i] = pri;
	}
	sort(a, a + n);

	int l = 0; while (a[l] == 1) ++l;

	int odd = 0, even_sum = l, init = l;
	for (int i = l, j = l; i < n; i = j) {
		while (j < n && a[j] == a[i]) ++j;
		ckmax(init, j - i);
		if ((j - i) & 1) ckmax(odd, j - i);
		else even_sum += j - i;
	}
	// rep(i, 0, n) cerr << a[i] << ' ';
	// cerr << '\n';
	int q; cin >> q;
	while (q--) {
		ll w; cin >> w;
		if (w == 0) cout << init << '\n';
		else cout << max(odd, even_sum) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	rep(i, 2, MX) {
		if (!lp[i]) lp[i] = i, pr.push_back(i);
		for (int j = 0; j < sz(pr) && pr[j] <= lp[i] && i * pr[j] < MX; ++j)
			lp[i * pr[j]] = pr[j];
	}

	int t; cin >> t;
	while (t--) solve();
}