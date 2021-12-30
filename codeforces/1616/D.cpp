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

constexpr ll inf = 1e18;

int solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;
	ll x; cin >> x;

	for (auto &y : a)
		y -= x;

	int ans = 0;
	for (int i = 0, j = 0; i < n; i = j + 1) {
		while (j < n && (j <= i || a[j] + a[j - 1] >= 0) && (j <= i + 1 || a[j] + a[j - 1] + a[j - 2] >= 0))
			++j;
		ans += j - i;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}
