#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, true : false; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, true : false; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	sort(all(a)); sort(all(b));

	int ans = 2e9 + 10;
	for (int i = 0, j = 0, k = 0; i < n; ++i) {
		while (j < m && b[j] < a[i]) ++j;
		while (k < m && b[k] <= a[i]) ++k;
		if (j < m) uin(ans, b[j] - a[i]);
		if (k > 0) uin(ans, a[i] - b[k - 1]);
	}

	cout << ans << '\n';
}
