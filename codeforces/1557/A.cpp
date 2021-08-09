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

double solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	sort(all(a));
	ll s = 0;
	rep(i, 0, n - 1) s += a[i];
	return double(s) / (n - 1) + a.back();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(10);
	int t; cin >> t;
	while (t--) cout << solve() << '\n';
}