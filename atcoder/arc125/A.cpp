#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

template<class T> bool uin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool uax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<int> a(n);
	bool exists[2] = {false, false};
	for (auto &x : a) cin >> x;
	for (auto x : a) exists[x] = true;

	vector<int> b(m);
	for (auto &x : b) cin >> x;
	for (auto x : b)
		if (!exists[x])
			return cout << "-1\n", 0;

	bool all_same = true;
	for (auto x : b)
		if (x != a[0])
			all_same = false;
	if (all_same)
		return cout << m << '\n', 0;

	// n - 1 -> 0, (n - 1) - i
	int ans = n;
	rep(i, 0, n)
		if (a[i] != a[0])
			uin(ans, min(i - 1, n - 1 - i));

	assert(ans < n);
	int state = a[0];
	for (auto x : b) {
		if (x != state) {
			++ans;
			state ^= 1;
		}
		++ans;
	}
	cout << ans << '\n';
}
