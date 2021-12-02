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

	int n; cin >> n;
	vector<int> a(n), b(n), c(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	for (auto &x : c) cin >> x;

	sort(all(a)); sort(all(b)); sort(all(c));
	vector<int> one(n + 1);
	for (int i = 0, j = 0; j < n; ++j) {
		while (i < n && a[i] < b[j])
			++i;
		one[j] = i;
	}

	ll ans = 0;
	ll cur = 0;
	for (int j = 0, k = 0; k < n; ++k) {
		while (j < n && b[j] < c[k]) {
			cur += one[j];
			++j;
		}
		ans += cur;
	}
	cout << ans << '\n';
}