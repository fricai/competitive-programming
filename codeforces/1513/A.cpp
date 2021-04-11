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

void solve() {
	int n, k; cin >> n >> k;
	if (n & 1) {
		if (k > n / 2) return void(cout << "-1\n");
	} else {
		if (k > n / 2 - 1) return void(cout << "-1\n");
	}
	
	vector<int> a(n);
	a[0] = 1;
	
	int r = k;
	int j = 2;
	for (int i = 2; i < n && r > 0; i += 2, --r, ++j)
		a[i] = j;
	r = k;
	for (int i = 1; i < n && r > 0; i += 2, --r, ++j)
		a[i] = j;
	for (int i = 0; i < n; ++i)
		if (!a[i]) a[i] = j++;
	for (auto x : a) cout << x << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();
}