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

	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	int ans = 0;
	for (int i = 0, j = 0; i < n; i = j) {
		while (j + 1 < n && a[j] != a[j + 1]) ++j;
		++j;
		if ((i ^ j) & 1) {
			rep(k, i, j) a[k] = a[i];
		} else {
			rep(k, i, (i + j) / 2) a[k] = a[i];
			rep(k, (i + j) / 2, j) a[k] = a[j - 1];
		}
		ckmax(ans, (j - i - 1) / 2);
	}

	cout << ans << '\n';
	for (auto x : a) cout << x << ' ';
}