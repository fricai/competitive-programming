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
	vector<int> s(n);
	for (auto &x : s)
		cin >> x;

	auto f = [](int a, int b) { return 4 * a * b + 3 * a + 3 * b; };

	int ans = n;
	for (auto x : s) {
		bool ok = false;
		for (int a = 1; a <= x; ++a) {
			// a * (4b + 3) + 3b
			for (int b = 1; f(a, b) <= x; ++b) {
				ok |= f(a, b) == x;
			}
		}
		ans -= ok;
	}
	cout << ans << '\n';
}
