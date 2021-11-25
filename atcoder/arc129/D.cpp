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
	vector<ll> a(n);
	for (auto &x : a)
		cin >> x;

	rep(i, 1, n) {
		a[i] += a[i - 1];
	}
	if (a.back() != 0)
		return void(cout << "-1\n"), 0;

	vector<ll> c(n);
	rep(i, 0, n) c[0] += a[i];
	if (c[0] % n != 0) {
		return void(cout << "-1\n"), 0;
	}
	c[0] = -c[0] / n;
	rep(i, 0, n - 1) c[i + 1] = c[0] + a[i];

	vector<ll> b(n);
	rep(i, 1, n) b[i] = b[i - 1] + c[i];
	b[0] = -*min_element(all(b));
	rep(i, 1, n) b[i] += b[0];

	cout << accumulate(all(b), 0ll) << '\n';
}
